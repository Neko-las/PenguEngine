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
    ~VertexArrayObject(){
        glDeleteVertexArrays(1,&id);
    }

    /**
     * generates a vertex Array binds it to an id
     */
    void generateVertexArray();

    /**
     *bindVertexArray
     */
    void bindVertexArray() const;

    /**
     * unbind vertexArray
     */
     void unbindVertexArray();

};

struct VertexBuffer{

    GLuint id;

    VertexBuffer();
    ~VertexBuffer(){
        unbindVertexBuffer();
        glDeleteBuffers(1,&id);
    }

    void generateBuffer();

    void transferFloatBuffer(GLfloat* data,long size);

    void bindVertexBuffer() const;

    void unbindVertexBuffer()const;

};

#endif //PENGUENGINE_BUFFER_HPP
