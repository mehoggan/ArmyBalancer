#include "glslversionselector.h"

#include <QDebug>

#include <iostream>
#include <stdexcept>

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
  #define snprintf _snprintf
#endif

std::shared_ptr<GLSLVersionSelector>
  GLSLVersionSelector::s_glslVersionSelector = nullptr;

std::shared_ptr<GLSLVersionSelector> GLSLVersionSelector::getSharedInstance()
{
  if (!s_glslVersionSelector) {
    s_glslVersionSelector.reset(new GLSLVersionSelector());
  }

  return s_glslVersionSelector;
}

GLSLVersionSelector::GLSLVersionSelector()
{
  initializeOpenGLFunctions();
}

std::string GLSLVersionSelector::getGLSLVersion()
{
  const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
  return std::string((const char*)(glslVersion));
}

std::string GLSLVersionSelector::getGLVersion()
{
  const GLubyte *glVersion = glGetString(GL_VERSION);
  return std::string((const char*)(glVersion));
}

std::shared_ptr<QResource> GLSLVersionSelector::getResourcePath(
  const std::string &shaderName)
{
  std::string glslVersion = getGLSLVersion();

  float ver = 0.0f;
  char *pch = strtok((char*)(glslVersion.c_str()), " ");
  while (pch != nullptr) {
    char* endptr;
    ver = std::strtod(pch, &endptr);
    if (*endptr == '\0') {
      break;
    }
    pch = strtok(nullptr, " ");
  }

  std::string uri = "shaders/";
  std::map<float, const char *> versionMap = {
    {1.1, "glsl_110"}, {2.0, "glsl_120"}, {2.1, "glsl_120"}, {3.0, "glsl_130"},
    {3.1, "glsl_140"}, {3.2, "glsl_150"}, {3.3, "glsl_330"}, {4.0, "glsl_400"},
    {4.1, "glsl_410"}, {4.2, "glsl_420"}, {4.3, "glsl_430"}, {4.4, "glsl_440"},
    {4.5, "glsl_450"}};
  auto it = versionMap.find(ver);
  if (it == versionMap.end()) {
    qFatal((QString("FATAL: Unsupported GLSL Version ") +
      QString::number(ver)).toStdString().c_str());
  }
  qDebug() << "Using " << ver << " for GLSL.";
  uri += (std::string(it->second) + std::string("/") + shaderName);

  return std::make_shared<QResource>(uri.c_str());
}
