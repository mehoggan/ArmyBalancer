#include "geometries/splines.h"

#include "glslversionselector.h"

#include <math/matrix.h>

#include <QDebug>
#include <QFile>
#include <QTextStream>

Spline::Spline()
  : m_vbo(0)
  , m_mvp(opengl_math::identity)
  , m_transform(opengl_math::identity)
{}

Spline::Spline(const Spline &other)
  : m_vbo(other.m_vbo)
  , m_vertexAttrib(other.m_vertexAttrib)
  , m_cubic(other.m_cubic)
  , m_mvp(other.m_mvp)
  , m_transform(other.m_transform)
{}

Spline &Spline::operator=(const Spline &rhs)
{
  m_vbo = rhs.m_vbo;
  m_vertexAttrib = rhs.m_vertexAttrib;
  m_cubic = rhs.m_cubic;
  m_mvp = rhs.m_mvp;
  m_transform = rhs.m_transform;

  return (*this);
}

Spline::~Spline()
{
  destroy();
  m_shaderManager.reset();
}

void Spline::create()
{
  initializeOpenGLFunctions();

  if (!m_shaderManager) {
    m_shaderManager = GLShaderResourceManager::getSharedInstance();
  }

  destroy();

  glGenBuffers(1, &m_vbo); GL_CALL

  std::vector<opengl_math::curve_sample_3d<float>> samples =
    m_cubic.compute_samples_adaptive(0.109999992);
  verts::collection_type data(new verts::datum_type[samples.size()]);
  std::size_t index = 0;
  for (const auto &sample : samples) {
    data[index++] = verts::datum_type(sample._position,
      opengl_math::color_rgba<float>(0.00f, 0.00f, 0.00f, 1.0f));
  }
  m_vertexAttrib = verts(data, samples.size());
  std::size_t bytes = m_vertexAttrib.get_byte_count();
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data().get(),
    GL_STATIC_DRAW); GL_CALL

  std::shared_ptr<GLSLVersionSelector> versionSelector =
    GLSLVersionSelector::getSharedInstance();
  std::shared_ptr<QResource> vshaderRes = versionSelector->getResourcePath(
    "projectedcolored_vshader.glsl");
  std::shared_ptr<QResource> fshaderRes = versionSelector->getResourcePath(
    "projectedcolored_fshader.glsl");

  bool success = true;
  m_handle = m_shaderManager->generateProgram({vshaderRes}, {fshaderRes},
    &success);
  if (!success) {
    throw std::runtime_error("Failed to generate program for spline.");
  }

  m_shaderVertexAttrib.resize(2);
  m_shaderVertexAttrib[0] = GLShaderResourceManager::GLShaderAttributes(
    verts::datum_type::internal_type1::dimension,
    verts::traits::stride,
    verts::traits::type1_byte_offset,
    "iPosition");
  m_shaderVertexAttrib[1] = GLShaderResourceManager::GLShaderAttributes(
    verts::datum_type::internal_type2::dimension,
    verts::traits::stride,
    verts::traits::type2_byte_offset,
    "iColor");
}

void Spline::draw()
{
  m_shaderManager->useProgram(m_handle);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  m_shaderManager->enableVertexAttribArrays(m_handle, m_shaderVertexAttrib);
  m_shaderManager->setUniformMatrix4X4(m_handle, m_mvp.to_gl_matrix(), "uMVP");
  glDrawArrays(GL_LINE_STRIP, 0, m_vertexAttrib.get_attribute_count()); GL_CALL
}

void Spline::destroy()
{
  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo); GL_CALL
  }

  m_shaderManager->destroyProgram(m_handle);
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

void Spline::debug() const
{
  const verts::collection_type &data = m_vertexAttrib.get_data();
  std::size_t attributeCount = m_vertexAttrib.get_attribute_count();
  for (std::size_t i = 0; i < attributeCount; ++i) {
    const auto &point = data[i]._datum1;
    int x = 0; x = x;
  }
}
