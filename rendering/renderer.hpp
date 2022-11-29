//
// Created by nicolas on 11/28/22.
//

#ifndef PENGUENGINE_RENDERER_HPP
#define PENGUENGINE_RENDERER_HPP

#include "buffer.hpp"

struct Renderer {

    GLuint programID;
    VertexBuffer vertexBuffer;
    VertexArrayObject vertexArrayObject;

    Renderer();
    ~Renderer() = default;

    void prepareRendering();

    void render() const;

    void cleanUpRenderer();
};

#endif //PENGUENGINE_RENDERER_HPP
