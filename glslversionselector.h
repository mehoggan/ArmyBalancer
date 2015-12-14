#ifndef GLSLVERSIONSELECTOR_H
#define GLSLVERSIONSELECTOR_H

#include <QtGui/QOpenGLFunctions>

#include <QResource>

#include <cstdint>
#include <memory>
#include <string>

class GLSLVersionSelector : public QOpenGLFunctions
{
public:
  /*! This function should only be called when a context is made current.
   */
  static std::shared_ptr<GLSLVersionSelector> getSharedInstance();

  std::string getGLSLVersion();
  std::string getGLVersion();
  std::shared_ptr<QResource> getResourcePath(const std::string &shaderName);

private:
  GLSLVersionSelector();

  static std::shared_ptr<GLSLVersionSelector> s_glslVersionSelector;
};

#endif // GLSLVERSIONSELECTOR_H
