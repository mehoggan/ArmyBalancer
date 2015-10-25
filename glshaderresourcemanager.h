#ifndef GLSHADERRESOURCEMANAGER_H
#define GLSHADERRESOURCEMANAGER_H

#include <QOpenGLFunctions>

#include "geometries/geometry.h"

#include <QResource>

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

class GLShaderResourceManager : public QOpenGLFunctions
{
public:
  struct GLShaderHandle
  {
  private:
    friend class GLShaderResourceManager;
    GLuint m_vertexShader;
    GLuint m_fragmentShader;
    GLuint m_shaderProgram;

  public:
    GLShaderHandle();

    GLuint vertexShader() const {return m_vertexShader;}
    GLuint fragmentShader() const {return m_fragmentShader;}
    GLuint shaderProgramId() const {return m_shaderProgram;}
    bool isValid() const;
  };

  struct GLShaderAttributes
  {
  private:
    friend class GLShaderResourceManager;
    std::size_t m_dimension;
    std::size_t m_stride;
    std::size_t m_byteOffset;
    std::string m_attribName;
    GLint m_position;


  public:
    GLShaderAttributes();

    GLShaderAttributes(
      std::size_t dimension,
      std::size_t stride,
      std::size_t byteOffset,
      const std::string &attribName);

    std::size_t dimension() const {return m_dimension;}
    std::size_t stride() const {return m_stride;}
    std::size_t byteOffset() const {return m_byteOffset;}
    const std::string &attribName() const {return m_attribName;}
    GLint position() const {return m_position;}
    bool isValid() const;
  };

public:
  /*! This function should only be called when a context is made current.
   */
  static std::shared_ptr<GLShaderResourceManager> getSharedInstance();

  GLShaderHandle generateProgram(
    const std::vector<std::shared_ptr<QResource>> &vertexSources,
    const std::vector<std::shared_ptr<QResource>> &fragmentSources,
    bool *succeded = nullptr);

  void useProgram(const GLShaderHandle &handle);
  void stopUsingProgram(const GLShaderHandle &handle);
  void destroyProgram(GLShaderHandle &handle);

  void enableVertexAttribArrays(const GLShaderHandle &handle,
    std::vector<GLShaderAttributes> &attribs);
  void enableVertexAttribArray(const GLShaderHandle &handle,
    const GLShaderAttributes &attrib);

  void setUniformMatrix4X4(const GLShaderHandle &handle,
    const GLfloat *matrix, const GLchar *name);

private:
  GLShaderResourceManager();

  bool getCompilerErrors(GLuint shaderId);
  bool getLinkerErrors(GLuint programId);

  static std::shared_ptr<GLShaderResourceManager> s_glShaderResourceManager;
};

#endif // GLSHADERRESOURCEMANAGER_H
