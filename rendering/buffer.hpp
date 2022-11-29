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
    void generateAndBindVertexArray();

    /**
     *
     */
    void BindVertexArray();

};

struct VertexBuffer{

    GLuint id;

    VertexBuffer();

    void generateAndBindBuffer();

    void transferFloatBuffer(const GLfloat* data);

    void bindBuffer() const;

};

#endif //PENGUENGINE_BUFFER_HPP
