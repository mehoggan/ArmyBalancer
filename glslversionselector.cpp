#include "glslversionselector.h"

#include <QDebug>

#include <iostream>
#include <stdexcept>

#include <stdio.h>
#include <string.h>

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
    ver = std::strtof(pch, &endptr);
    if (*endptr == '\0') {
      break;
    }
    pch = strtok(nullptr, " ");
  }

  std::string uri = "shaders/";
  if (ver == 1.1 || ver == 1.10) {
  } else if (ver == 1.1 || ver == 1.10) {
    uri += ("glsl_110/" + shaderName);
  } else if (ver == 4.5 || ver == 4.50) {
    uri += ("glsl_450/" + shaderName);
  } else {
    const std::uint8_t size = 5;
    char buf[size];
    snprintf(buf, size, "%f", ver);
    std::string err(buf);
    throw std::runtime_error("Unsupported version " + err + "found");
  }

  return std::make_shared<QResource>(uri.c_str());
}
