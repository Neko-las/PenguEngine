//
// Created by nicolas on 2/21/23.
//

#ifndef PENGUENGINE_VERTEXBUFFER_HPP
#define PENGUENGINE_VERTEXBUFFER_HPP

#include "glad/glad.h"

struct VertexBuffer{
private:
    GLuint id;
public:
    VertexBuffer(unsigned size, GLfloat* data);
    ~VertexBuffer();
    void bind();
    void unbind();
    void uploadData(unsigned size, GLfloat* data);
};

#endif //PENGUENGINE_VERTEXBUFFER_HPP
