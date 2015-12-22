#ifndef NAMETEXTUREATLASMAP_H
#define NAMETEXTUREATLASMAP_H

#include "gltextureresourcemanager.h"

#include "bounds/axis_aligned_2d.h"

#include <QImage>

#include <string>
#include <unordered_map>

class NameTextureAtlasMap
{
public:
  NameTextureAtlasMap();

  void clearAtlas();
  void generateAtlas(const std::vector<std::string> &names);
  opengl_math::axis_aligned_2d<float> getUVForName(const std::string &name);
  void createTexture();

  const GLTextureResourceManager::GLTextureHandle &textureHandle() const
  {return m_texHandles[0];}

private:
  std::shared_ptr<GLTextureResourceManager> m_textureManager;
  using map_t = std::unordered_map<std::string,
    opengl_math::axis_aligned_2d<float>>;
  map_t m_nameToUVCoordsMap;
  QImage *m_atlas;
  GLTextureResourceManager::GLTextureHandle m_texHandles[1];
  bool m_firstRun;
};

#endif // NAMETEXTUREATLASMAP_H
