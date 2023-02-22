//
// Created by nicolas on 2/21/23.
//

#ifndef PENGUENGINE_VERTEXARRAY_HPP
#define PENGUENGINE_VERTEXARRAY_HPP


#include "glad/glad.h"
#include "VertexBuffer.hpp"
#include "ElementBuffer.hpp"

struct VertexArray {

public:

    VertexArray();
    ~VertexArray();

    void bind();
    void unbind();
    void setLayout(VertexBuffer* vertexBuffer, ElementBuffer* elementBuffer);

private:
    GLuint id;
};

#endif //PENGUENGINE_VERTEXARRAY_HPP
