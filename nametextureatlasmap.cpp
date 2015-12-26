#include "nametextureatlasmap.h"

#include <QFontMetrics>
#include <QGLWidget>
#include <QPainter>

NameTextureAtlasMap::NameTextureAtlasMap()
  : m_firstRun(true)
{}

void NameTextureAtlasMap::clearAtlas()
{
  m_atlas = QImage();
  m_nameToUVCoordsMap.clear();
}

const int atlasSize = 4096;
const float atlasSizeF = (float)atlasSize;

void NameTextureAtlasMap::generateAtlas(const std::vector<std::string> &names)
{
  if (names.empty()) {
    return;
  }

  const float stepf = 512.0f;
  const int stepi = 512;
  const float textWidth = stepf - 10.0;

  QImage tmp = QImage(atlasSize, atlasSize, QImage::Format_ARGB32);
  tmp.fill(Qt::blue);
  QPainter painter(&tmp);
  painter.setRenderHints(QPainter::Antialiasing |
    QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);

  int xPixel = 0;
  int yPixel = 0;

  for (const auto &name : names) {
    if (m_nameToUVCoordsMap.find(name) == m_nameToUVCoordsMap.end()) {
      QRectF rect(QPointF(xPixel, yPixel), QSizeF(stepf, stepf));
      QFont font = painter.font();
      font.setPointSize(36.0);
      font.setBold(true);
      while (QFontMetricsF(font).boundingRect(name.c_str()).width() >
        textWidth) {
        font.setPointSize(font.pointSize() - 1.0);
      }
      painter.setFont(font);
      painter.setPen(Qt::black);
      painter.fillRect(rect, Qt::green);
      auto flags = Qt::AlignHCenter | Qt::AlignVCenter;
      painter.drawText(rect, flags, name.c_str(), nullptr);

      opengl_math::axis_aligned_2d<float> bbox(
        opengl_math::point_2d<float>(xPixel, atlasSizeF - yPixel),
        opengl_math::point_2d<float>(xPixel + stepi, (atlasSizeF - yPixel) -
        stepi));

      xPixel += stepi;
      if (xPixel == atlasSize) {
        xPixel = 0;
        yPixel += stepi;
      }
      m_nameToUVCoordsMap.insert(std::make_pair(name, bbox));
    }
  }

  QImage tmp2 = QGLWidget::convertToGLFormat(tmp);

  if (m_atlas.size() != QSize()) {
    m_atlas = QImage();
  }

  m_atlas = QImage(tmp2);
}

opengl_math::axis_aligned_2d<float> NameTextureAtlasMap::getUVForName(
  const std::string &name)
{
  opengl_math::axis_aligned_2d<float> ret;
  auto it = m_nameToUVCoordsMap.find(name);
  if (it != m_nameToUVCoordsMap.end()) {
    ret = it->second;
    // Normalize to UV space not image space
    ret.r_ll().xref() /= atlasSizeF;
    ret.r_ll().yref() /= atlasSizeF;
    ret.r_ur().xref() /= atlasSizeF;
    ret.r_ur().yref() /= atlasSizeF;
  }
  return ret;
}

void NameTextureAtlasMap::createTexture()
{
  if (!m_textureManager) {
    m_textureManager = GLTextureResourceManager::getSharedInstance();
  }

  if (!m_firstRun) {
    m_textureManager->destroyTexture(m_texHandles[0]);
  }

  m_texHandles[0] = m_textureManager->createTextureResource();
  m_textureManager->uploadTexture(m_atlas, m_texHandles[0]);
  m_textureManager->setTextureParameters(m_texHandles[0], {
      GLTextureResourceManager::GLTextureParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE),
      GLTextureResourceManager::GLTextureParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE),
      GLTextureResourceManager::GLTextureParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR),
      GLTextureResourceManager::GLTextureParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR),
    });
  m_firstRun = false;
}
