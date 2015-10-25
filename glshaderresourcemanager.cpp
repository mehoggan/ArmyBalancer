#include "glshaderresourcemanager.h"

#include <QDebug>
#include <QFile>

#include <iostream>
#include <stdexcept>
#include <sstream>

#include <stdio.h>
#include <string.h>

std::shared_ptr<GLShaderResourceManager>
  GLShaderResourceManager::s_glShaderResourceManager = nullptr;

GLShaderResourceManager::GLShaderHandle::GLShaderHandle()
  : m_vertexShader(0)
  , m_fragmentShader(0)
  , m_shaderProgram(0)
{}

bool GLShaderResourceManager::GLShaderHandle::isValid() const
{
  return (m_vertexShader != 0) && (m_fragmentShader != 0) &&
    (m_shaderProgram != 0);
}

GLShaderResourceManager::GLShaderAttributes::GLShaderAttributes(
  std::size_t dimension,
  std::size_t stride,
  std::size_t byteOffset,
  const GLchar *attribName)
  : m_dimension(dimension)
  , m_stride(stride)
  , m_byteOffset(byteOffset)
  , m_attribName(attribName)
{}

std::shared_ptr<GLShaderResourceManager>
GLShaderResourceManager::getSharedInstance()
{
  struct make_shared_enabler : public GLShaderResourceManager
  {};

  if (!s_glShaderResourceManager) {
    s_glShaderResourceManager = std::make_shared<make_shared_enabler>();
  }

  return s_glShaderResourceManager;
}

GLShaderResourceManager::GLShaderResourceManager()
{
  initializeOpenGLFunctions();
}

GLShaderResourceManager::GLShaderHandle
GLShaderResourceManager::generateProgram(
  const std::shared_ptr<QResource> &vertexSource,
  const std::shared_ptr<QResource> &fragmentSource,
  bool *succeded)
{
  GLShaderHandle handle;

  QFile vshaderFile(vertexSource->absoluteFilePath());
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw std::runtime_error(std::string("Could not open ") +
      vshaderFile.fileName().toStdString());
  }
  QTextStream vshaderStream(&vshaderFile);
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); GL_CALL
  const GLchar *vshaderRaw = vshaderStream.readAll().toStdString().c_str();
  glShaderSource(vertexShader, 1, &(vshaderRaw), NULL); GL_CALL
  glCompileShader(vertexShader); GL_CALL
  if (getCompilerErrors(vertexShader)) {
    glDeleteShader(vertexShader);
    if (succeded) {
      (*succeded) = false;
    }
    return handle;
  }

  QFile fshaderFile(fragmentSource->absoluteFilePath());
  if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw std::runtime_error(std::string("Could not open ") +
      fshaderFile.fileName().toStdString());
  }
  QTextStream fshaderStream(&fshaderFile);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); GL_CALL
  const GLchar *fshaderRaw = fshaderStream.readAll().toStdString().c_str();
  glShaderSource(fragmentShader, 1, &(fshaderRaw), NULL); GL_CALL
  glCompileShader(fragmentShader); GL_CALL
  if (getCompilerErrors(fragmentShader)) {
    glDeleteShader(fragmentShader);
    if (succeded) {
      (*succeded) = false;
    }
    return handle;
  }

  GLuint shaderProgram = glCreateProgram(); GL_CALL
  glAttachShader(shaderProgram, vertexShader); GL_CALL
  glAttachShader(shaderProgram, fragmentShader); GL_CALL
  glLinkProgram(shaderProgram); GL_CALL
  if (getLinkerErrors(shaderProgram)) {
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteProgram(shaderProgram);
    if (succeded) {
      (*succeded) = false;
    }
    return handle;
  }

  handle.m_vertexShader = vertexShader;
  handle.m_fragmentShader = fragmentShader;
  handle.m_shaderProgram = shaderProgram;

  return handle;
}

GLShaderResourceManager::GLShaderHandle
GLShaderResourceManager::generateProgram(
  const std::vector<std::shared_ptr<QResource>> &vertexSources,
  const std::vector<std::shared_ptr<QResource>> &fragmentSources,
  bool *succeded)
{
  GLShaderHandle handle;

  const GLchar **combinedVSources = new const GLchar*[vertexSources.size()];
  std::size_t i = 0;
  for (auto vertexSource : vertexSources) {
    QFile vshaderFile(vertexSource->absoluteFilePath());
    if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
      throw std::runtime_error(std::string("Could not open ") +
        vshaderFile.fileName().toStdString());
    }
    QTextStream vshaderStream(&vshaderFile);
    std::string source = vshaderStream.readAll().toStdString();
    combinedVSources[i] = new GLchar[source.size() + 1];
    strcpy(const_cast<GLchar*>(combinedVSources[i]), source.c_str());
    ++i;
  }
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); GL_CALL
  glShaderSource(vertexShader, vertexSources.size(),
    combinedVSources, NULL); GL_CALL
  glCompileShader(vertexShader); GL_CALL
  if (getCompilerErrors(vertexShader)) {
    glDeleteShader(vertexShader);
    if (succeded) {
      (*succeded) = false;
    }
    return handle;
  }

  const GLchar **combinedFSources = new const GLchar*[fragmentSources.size()];
  std::size_t j = 0;
  for (auto fragmentSource : fragmentSources) {
    QFile fshaderFile(fragmentSource->absoluteFilePath());
    if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
      throw std::runtime_error(std::string("Could not open ") +
        fshaderFile.fileName().toStdString());
    }
    QTextStream fshaderStream(&fshaderFile);
    std::string source = fshaderStream.readAll().toStdString();
    combinedFSources[j] = new GLchar[source.size() + 1];
    strcpy(const_cast<GLchar*>(combinedFSources[j]), source.c_str());
    ++j;
  }
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); GL_CALL
  glShaderSource(fragmentShader, fragmentSources.size(),
    combinedFSources, NULL); GL_CALL
  glCompileShader(fragmentShader); GL_CALL
  if (getCompilerErrors(fragmentShader)) {
    glDeleteShader(fragmentShader);
    if (succeded) {
      (*succeded) = false;
    }
    return handle;
  }

  GLuint shaderProgram = glCreateProgram(); GL_CALL
  glAttachShader(shaderProgram, vertexShader); GL_CALL
  glAttachShader(shaderProgram, fragmentShader); GL_CALL
  glLinkProgram(shaderProgram); GL_CALL
  if (getLinkerErrors(shaderProgram)) {
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteProgram(shaderProgram);
    if (succeded) {
      (*succeded) = false;
    }
    return handle;
  }

  handle.m_vertexShader = vertexShader;
  handle.m_fragmentShader = fragmentShader;
  handle.m_shaderProgram = shaderProgram;

  return handle;
}

void GLShaderResourceManager::useProgram(const GLShaderHandle &handle)
{
  glUseProgram(handle.shaderProgramId());
}

void GLShaderResourceManager::stopUsingProgram(const GLShaderHandle &/*handle*/)
{
  glUseProgram(0);
}

void GLShaderResourceManager::destroyProgram(GLShaderHandle &handle)
{
  if (glIsShader(handle.vertexShader())) {
    glDeleteShader(handle.vertexShader());
    handle.m_vertexShader = 0;
  }

  if (glIsShader(handle.fragmentShader())) {
    glDeleteShader(handle.fragmentShader());
    handle.m_fragmentShader = 0;
  }

  if (glIsProgram(handle.shaderProgramId())) {
    glDeleteProgram(handle.shaderProgramId());
    handle.m_shaderProgram = 0;
  }
}

void GLShaderResourceManager::enableVertexAttribArrays(
  const GLShaderHandle &handle, std::vector<GLShaderAttributes> &attribs)
{
  for (auto attrib : attribs) {
    enableVertexAttribArray(handle, attrib);
  }
}

void GLShaderResourceManager::enableVertexAttribArray(
  const GLShaderHandle &handle, const GLShaderAttributes &attrib)
{
  GLint attribPos = glGetAttribLocation(handle.m_shaderProgram,
    attrib.attribName()); GL_CALL
  glEnableVertexAttribArray(attribPos); GL_CALL
  glVertexAttribPointer(attribPos, attrib.m_position, GL_FLOAT, GL_FALSE,
    attrib.stride(), (void*)attrib.m_byteOffset); GL_CALL
  const_cast<GLShaderAttributes &>(attrib).m_position = attribPos;
}

bool GLShaderResourceManager::getCompilerErrors(GLuint shaderId)
{
  bool errors = false;

  GLint isCompiled = 0;

  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled); GL_CALL
  if(isCompiled == GL_FALSE) {
    GLint maxLength = 0;
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength); GL_CALL
    std::vector<GLchar> errorLog(maxLength);
    glGetShaderInfoLog(shaderId, maxLength, &maxLength, &errorLog[0]); GL_CALL
    std::stringstream out;
    std::copy(errorLog.begin(), errorLog.end(), std::ostream_iterator<char>(
      out, ""));
    qDebug() << out.str().c_str();
    errors = true;
  }

  return errors;
}

bool GLShaderResourceManager::getLinkerErrors(GLuint programId)
{
  bool errors = false;

  GLint isLinked = 0;

  glGetProgramiv(programId, GL_LINK_STATUS, &isLinked);
  if(isLinked == GL_FALSE) {
    GLint maxLength = 0;
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength); GL_CALL
    std::vector<GLchar> infoLog(maxLength);
    glGetProgramInfoLog(programId, maxLength, &maxLength, &infoLog[0]); GL_CALL
    std::stringstream out;
    std::copy(infoLog.begin(), infoLog.end(), std::ostream_iterator<char>(
      out, ""));
    qDebug() << out.str().c_str();
    errors = true;
  }

  return errors;
}

