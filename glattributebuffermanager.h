#ifndef GLATTRIBUTEBUFFERMANAGER_H
#define GLATTRIBUTEBUFFERMANAGER_H

#include <QOpenGLFunctions>

#include "geometries/geometry.h"

#include <memory>
#include <typeindex>
#include <unordered_map>

class GLAttributeBufferManager : public QOpenGLFunctions
{
public:
  class GLBufferHandle
  {
  private:
    GLuint m_vboId;
    GLuint m_eboId;
    std::type_index m_type;
    std::type_index m_indexType;
    std::size_t m_offset;
    std::size_t m_indexOffset;
    std::size_t m_bytesCount;
    std::size_t m_indexByteCount;
    std::size_t m_maxIndex;

  public:
    GLBufferHandle();

    GLuint vboId() const {return m_vboId;}
    GLuint eboId() const {return m_eboId;}
    std::type_index type() const {return m_type;}
    std::type_index indexType() const {return m_indexType;}
    std::size_t offset() const {return m_offset;}
    std::size_t indexOffset() const {return m_indexOffset;}
    std::size_t byteCount() const {return m_bytesCount;}
    std::size_t indexByteCount() const {return m_indexByteCount;}
    std::size_t maxIndex() const {return m_maxIndex;}
  };

  // Default Buffer Name
  class DBN {};

public:
  /*! This function should only be called when a context is made current.
   */
  static std::shared_ptr<GLAttributeBufferManager> getSharedInstance();

  template<typename AttributeType, typename NamedType = DBN>
  GLBufferHandle addDatumToNamedBuffer(const AttributeType &type);

  template<typename AttributeType, typename IndexType, typename NamedType = DBN>
  GLBufferHandle addDatumToNamedIndexedBuffer(const AttributeType &type,
    const IndexType &indices, std::size_t maxIndex);

  void drawBuffer(const GLBufferHandle &handle);

  void drawIndexedBuffer(const GLBufferHandle &handle);

private:
  GLBufferHandle addDatumToNamedBuffer(GLBufferHandle &handle, void *data);
  GLBufferHandle addDatumToNamedIndexedBuffer(GLBufferHandle &handle,
    void *data);

private:
  std::unordered_map<std::type_index, GLBufferHandle> m_attributeBuffers;
  typedef std::pair<std::type_index, std::type_index> IndicesIndex_t;
  std::unordered_map<IndicesIndex_t, GLBufferHandle> m_attributeIndexBuffers;
  std::unordered_map<IndicesIndex_t, std::size_t> m_maxIndexForBuffer;
};

#endif // GLATTRIBUTEBUFFERMANAGER_H
