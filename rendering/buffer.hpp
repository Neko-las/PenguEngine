//
// Created by nicolas on 11/28/22.
//
#include <glad/glad.h>

#ifndef PENGUENGINE_BUFFER_HPP
#define PENGUENGINE_BUFFER_HPP

struct VertexArrayObject{
    GLuint id;

    /**
     * create a VertexArrayObject (VAO)
     */
    VertexArrayObject();

    /**
     * generates a vertex Array binds it to an id
     */
    void generateVertexArray();

    /**
     *
     */
    void bindVertexArray();

};

struct VertexBuffer{

    GLuint id;

    VertexBuffer();

    void generateBuffer();

    void transferFloatBuffer(GLfloat* data,long size);

    void bindBuffer() const;

};

#endif //PENGUENGINE_BUFFER_HPP
