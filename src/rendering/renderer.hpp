//
// Created by nicolas on 11/28/22.
//

#ifndef PENGUENGINE_RENDERER_HPP
#define PENGUENGINE_RENDERER_HPP

#include "buffer/VertexArray.hpp"
#include "buffer/VertexBuffer.hpp"
#include "buffer/ElementBuffer.hpp"

struct Renderer {

    GLuint programID;
    GLuint program2ID;

    Renderer();
    ~Renderer() = default;

    void prepareRendering(VertexArray *vertexArray, VertexBuffer *vertexBuffer, ElementBuffer *pBuffer);

    void render(VertexArray *pArray) const;

    void cleanUpRenderer();
};

#endif //PENGUENGINE_RENDERER_HPP
