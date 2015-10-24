#include "geometries/splines.h"

#include <math/matrix.h>

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

#include <sstream>

Spline::Spline() :
  m_shaderProgram(0),
  m_vertexShader(0),
  m_fragmentShader(0),
  m_vbo(0),
  m_lineWidth(0.1f),
  m_pointSize(0.5f),
  m_displayPoints(false),
  m_displayTangents(false),
  m_projection(opengl_math::identity)
{}

Spline::Spline(const Spline &other) :
  m_shaderProgram(other.m_shaderProgram),
  m_vertexShader(other.m_vertexShader),
  m_fragmentShader(other.m_fragmentShader),
  m_vbo(other.m_vbo),
  m_lineWidth(other.m_lineWidth),
  m_pointSize(other.m_pointSize),
  m_displayPoints(other.m_displayPoints),
  m_displayTangents(other.m_displayTangents),
  m_vertexAttrib(other.m_vertexAttrib),
  m_projection(other.m_projection),
  m_cubic(other.m_cubic),
  m_color(other.m_color)
{}

Spline &Spline::operator=(const Spline &rhs)
{
  m_shaderProgram = rhs.m_shaderProgram;
  m_vertexShader = rhs.m_vertexShader;
  m_fragmentShader = rhs.m_fragmentShader;
  m_vbo = rhs.m_vbo;
  m_lineWidth = rhs.m_lineWidth;
  m_pointSize = rhs.m_pointSize;
  m_displayPoints = rhs.m_displayPoints;
  m_displayTangents = rhs.m_displayTangents;
  m_vertexAttrib = rhs.m_vertexAttrib;
  m_projection = rhs.m_projection;
  m_cubic = rhs.m_cubic;
  m_color = rhs.m_color;

  return (*this);
}

Spline::~Spline()
{
  destroy();
}

void Spline::setProjection(
  const opengl_math::matrix_4X4<float, opengl_math::column> &projection)
{
  m_projection = projection;
}

void Spline::create()
{
  initializeOpenGLFunctions();

  destroy();

  qDebug() << "Loading vertex shader file";
  QFile vshaderFile(
    ":/shaders/projectedcoloredgeometry_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  qDebug() << "Loading fragment shader file";
  QFile fshaderFile(
    ":/shaders/projectedcoloredgeometry_fshader.glsl");
  if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      fshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream fshaderStream(&fshaderFile);
  std::string fshaderSrc = fshaderStream.readAll().toStdString();

  glGenBuffers(1, &m_vbo); GL_CALL

  std::vector<opengl_math::curve_sample_3d<float>> samples =
    m_cubic.compute_samples_adaptive(0.109999992);
  verts::collection_type data(new verts::datum_type[samples.size()]);
  std::size_t index = 0;
  for (const auto &sample : samples) {
    data[index++] = verts::datum_type(sample._position,
      opengl_math::color_rgba<float>(0.0f, 0.0f, 0.0f, 1.0f));
  }

  m_vertexAttrib = verts(data, samples.size());

  std::size_t bytes = m_vertexAttrib.get_byte_count();

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data().get(),
    GL_STATIC_DRAW); GL_CALL

  // Create and compile the vertex shader
  m_vertexShader = glCreateShader(GL_VERTEX_SHADER); GL_CALL
  const GLchar *vshaderRaw = vshaderSrc.c_str();
  glShaderSource(m_vertexShader, 1, &(vshaderRaw), NULL); GL_CALL
  glCompileShader(m_vertexShader); GL_CALL

  GLint isCompiled = 0;

  qDebug() << "Compiling vertex shader program";
  glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &isCompiled); GL_CALL
  if(isCompiled == GL_FALSE) {
    GLint maxLength = 0;
    glGetShaderiv(m_vertexShader, GL_INFO_LOG_LENGTH, &maxLength); GL_CALL
    std::vector<GLchar> errorLog(maxLength);
    glGetShaderInfoLog(m_vertexShader, maxLength, &maxLength, &errorLog[0]);
    GL_CALL
    std::stringstream out;
    std::copy(errorLog.begin(), errorLog.end(), std::ostream_iterator<char>(
      out, ""));
    qDebug() << out.str().c_str();
    glDeleteShader(m_vertexShader); GL_CALL
    QCoreApplication::exit(-1);
  }

  // Create and compile the fragment shader
  qDebug() << "Compiling fragment shader program";
  m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); GL_CALL
  const GLchar *fshaderRaw = fshaderSrc.c_str();
  glShaderSource(m_fragmentShader, 1, &(fshaderRaw), NULL); GL_CALL
  glCompileShader(m_fragmentShader); GL_CALL
  glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &isCompiled); GL_CALL
  if(isCompiled == GL_FALSE) {
    GLint maxLength = 0;
    glGetShaderiv(m_fragmentShader, GL_INFO_LOG_LENGTH, &maxLength); GL_CALL
    std::vector<GLchar> errorLog(maxLength);
    glGetShaderInfoLog(m_fragmentShader, maxLength, &maxLength, &errorLog[0]);
    GL_CALL
    std::stringstream out;
    std::copy(errorLog.begin(), errorLog.end(), std::ostream_iterator<char>(
      out, ""));
    qDebug() << out.str().c_str();
    glDeleteShader(m_fragmentShader); GL_CALL
    QCoreApplication::exit(-1);
  }

  // Link the vertex and fragment shader into a shader program
  qDebug() << "Linking shader program";
  m_shaderProgram = glCreateProgram(); GL_CALL
  glAttachShader(m_shaderProgram, m_vertexShader); GL_CALL
  glAttachShader(m_shaderProgram, m_fragmentShader); GL_CALL
  glLinkProgram(m_shaderProgram); GL_CALL

  GLint isLinked = 0;
  glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, (int *)&isLinked);
  if(isLinked == GL_FALSE) {
    GLint maxLength = 0;
    glGetProgramiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &maxLength); GL_CALL
    std::vector<GLchar> infoLog(maxLength);
    glGetProgramInfoLog(m_shaderProgram, maxLength, &maxLength, &infoLog[0]);
    GL_CALL
    std::stringstream out;
    std::copy(infoLog.begin(), infoLog.end(), std::ostream_iterator<char>(
      out, ""));
    qDebug() << out.str().c_str();
    glDeleteProgram(m_shaderProgram); GL_CALL
    glDeleteShader(m_vertexShader); GL_CALL
    glDeleteShader(m_fragmentShader); GL_CALL
    QCoreApplication::exit(-1);
  }
}

void Spline::draw()
{
  glUseProgram(m_shaderProgram); GL_CALL

  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "iPosition"); GL_CALL
  GLint colAttrib = glGetAttribLocation(m_shaderProgram, "iColor"); GL_CALL

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  std::size_t stride = verts::traits::stride;

  std::size_t dimension1 = verts::datum_type::internal_type1::dimension;
  std::size_t byte_offset1 = verts::traits::type1_byte_offset;
  glEnableVertexAttribArray(posAttrib); GL_CALL
  glVertexAttribPointer(posAttrib, dimension1, GL_FLOAT, GL_FALSE,
    stride, (void*)byte_offset1); GL_CALL

  std::size_t dimension2 = verts::datum_type::internal_type2::dimension;
  std::size_t byte_offset2 = verts::traits::type2_byte_offset;
  glEnableVertexAttribArray(colAttrib); GL_CALL
  glVertexAttribPointer(colAttrib, dimension2, GL_FLOAT, GL_FALSE,
    stride, (void*)byte_offset2); GL_CALL

  opengl_math::matrix_4X4<float, opengl_math::column> model(
    opengl_math::identity);
  opengl_math::matrix_4X4<float, opengl_math::column> view =
    opengl_math::look_at<float, opengl_math::column>(
      opengl_math::point_3d<float>(0.0f, 0.0f, 20.0f),
      opengl_math::point_3d<float>(0.0f, 0.0f, 0.0f),
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f));

  GLint uniMVP = glGetUniformLocation(m_shaderProgram, "uMVP"); GL_CALL
  glUniformMatrix4fv(uniMVP, 1, GL_FALSE,
    (m_projection * view * model).to_gl_matrix()); GL_CALL

  glDrawArrays(GL_LINE_STRIP, 0, m_vertexAttrib.get_attribute_count());
  GL_CALL
}

void Spline::destroy()
{
  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo); GL_CALL
  }

  if (glIsProgram(m_shaderProgram)) {
    glDeleteProgram(m_shaderProgram); GL_CALL
  }

  if (glIsShader(m_vertexShader)) {
    glDeleteShader(m_vertexShader); GL_CALL
  }

  if (glIsShader(m_fragmentShader)) {
    glDeleteShader(m_fragmentShader); GL_CALL
  }
}

std::shared_ptr<Spline> Spline::createBezier(
  const opengl_math::point_3d<float> &p0,
  const opengl_math::point_3d<float> &p1,
  const opengl_math::point_3d<float> &p2,
  const opengl_math::point_3d<float> &p3)
{
  std::shared_ptr<Spline> s(new Spline());
  s->m_cubic.set_bezier(p0, p1, p2, p3);
  return s;
}

std::shared_ptr<Spline> Spline::createHermite(
  const opengl_math::point_3d<float> &p0,
  const opengl_math::point_3d<float> &p1,
  const opengl_math::vector_3d<float> &t0,
  const opengl_math::vector_3d<float> &t1)
{
  std::shared_ptr<Spline> s(new Spline());
  s->m_cubic.set_hermite(p0, p1, t0, t1);
  return s;
}
