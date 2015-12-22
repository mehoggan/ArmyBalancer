#include "gltextureresourcemanager.h"

#include <iostream>
#include <QDebug>

std::shared_ptr<GLTextureResourceManager>
  GLTextureResourceManager::s_glTextureResourceManager = nullptr;

GLTextureResourceManager::GLTextureHandle::GLTextureHandle()
  : m_textureId(0)
  , m_activeId(-1)
{}

GLTextureResourceManager::GLTextureHandle::~GLTextureHandle()
{}

GLTextureResourceManager::GLTextureParameteri::GLTextureParameteri()
  : m_target(-1)
  , m_pname(-1)
  , m_param(-1)
{}

GLTextureResourceManager::GLTextureParameteri::GLTextureParameteri(
  GLenum target,
  GLenum pname,
  GLint param)
  : m_target(target)
  , m_pname(pname)
  , m_param(param)
{}

bool GLTextureResourceManager::GLTextureParameteri::isValid() const
{
  return ((GLint)m_target != -1) && ((GLint)m_pname != -1) && (m_param != -1);
}

std::shared_ptr<GLTextureResourceManager>
GLTextureResourceManager::getSharedInstance()
{
  if (!s_glTextureResourceManager) {
    s_glTextureResourceManager.reset(new GLTextureResourceManager());
  }

  return s_glTextureResourceManager;
}

GLTextureResourceManager::GLTextureResourceManager()
  : m_activeTextures(0)
{
  initializeOpenGLFunctions();

  GLint textureUnits;
  glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &textureUnits);

  std::int32_t count = textureUnits;
  std::vector<std::int32_t> tmp(textureUnits);
  std::generate(tmp.begin(), tmp.end(), [&](){return (--count);});
  m_inactiveTextures = std::unordered_set<std::int32_t>(tmp.begin(), tmp.end());
}

GLTextureResourceManager::GLTextureHandle
GLTextureResourceManager::createTextureResource()
{
  GLTextureHandle handle;
  glGenTextures(1, &(handle.m_textureId)); GL_CALL

  return handle;
}

void GLTextureResourceManager::uploadTexture(const QImage &image,
  const GLTextureHandle &handle)
{
  glBindTexture(GL_TEXTURE_2D, handle.m_textureId); GL_CALL
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0,
    GL_RGBA, GL_UNSIGNED_BYTE, image.bits()); GL_CALL
}

void GLTextureResourceManager::setTextureParameters(
  const GLTextureHandle &handle,
  const std::vector<GLTextureParameteri> &params)
{
  glBindTexture(GL_TEXTURE_2D, handle.m_textureId);
  for (auto param : params) {
    glTexParameteri(param.m_target, param.m_pname, param.m_param); GL_CALL
  }
}

void GLTextureResourceManager::activateTexture(const GLTextureHandle &handle)
{
  glBindTexture(GL_TEXTURE_2D, handle.m_textureId); GL_CALL
}

void GLTextureResourceManager::deactivateTexture(const GLTextureHandle &)
{
  glBindTexture(GL_TEXTURE_2D, 0); GL_CALL
}

void GLTextureResourceManager::destroyTexture(const GLTextureHandle &handle)
{
  if (glIsTexture(handle.m_textureId)) {
    glDeleteTextures(1, &handle.m_textureId);
  }
}

void GLTextureResourceManager::destroyTextures(
  const std::vector<GLTextureHandle> &handles)
{
  for (auto &handle : handles) {
    destroyTexture(handle);
  }
}
