#ifndef GLTEXTURERESOURCEMANAGER_H
#define GLTEXTURERESOURCEMANAGER_H

#include <QOpenGLFunctions>

#include "geometries/geometry.h"

#include "ref_count/shared_array/shared_array.h"

#include <QImage>
#include <QResource>

#include <atomic>
#include <memory>
#include <string>
#include <unordered_set>

class GLTextureResourceManager : public QOpenGLFunctions
{
public:
  struct GLTextureHandle
  {
  private:
    friend class GLTextureResourceManager;
    GLuint m_textureId;
    GLint m_activeId;

  public:
    GLTextureHandle();
    ~GLTextureHandle();

    GLuint textureId() const {return m_textureId;}
    GLint activeId() const {return m_activeId;}
  };

  struct GLTextureParameteri
  {
  private:
    friend class GLTextureResourceManager;
    GLenum m_target;
    GLenum m_pname;
    GLint m_param;

  public:
    GLTextureParameteri();

    GLTextureParameteri(
      GLenum target,
      GLenum pname,
      GLint param);

    GLenum target() const {return m_target;}
    GLenum pname() const {return m_pname;}
    GLint param() const {return m_param;}
    bool isValid() const;
  };

public:
  /*! This function should only be called when a context is made current.
   */
  static std::shared_ptr<GLTextureResourceManager> getSharedInstance();

  GLTextureHandle createTextureResource();

  void uploadTexture(const QImage &image, const GLTextureHandle &handle);

  void setTextureParameters(const GLTextureHandle &handle,
    const std::vector<GLTextureParameteri> &params);

  void activateTexture(const GLTextureHandle &handle);

  void deactivateTexture(const GLTextureHandle &);

  void destroyTexture(const GLTextureHandle &handle);

  void destroyTextures(const std::vector<GLTextureHandle> &handles);

private:
  GLTextureResourceManager();

  GLTextureResourceManager(const GLTextureResourceManager&) = delete;
  GLTextureResourceManager &operator=(const GLTextureResourceManager&) = delete;

  static std::shared_ptr<GLTextureResourceManager> s_glTextureResourceManager;

private:
  std::unordered_set<std::int32_t> m_activeTextures;
  std::unordered_set<std::int32_t> m_inactiveTextures;
};

#endif // GLTEXTURERESOURCEMANAGER_H
