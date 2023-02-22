//
// Created by nicolas on 2/21/23.
//

#ifndef PENGUENGINE_ELEMENTBUFFER_HPP
#define PENGUENGINE_ELEMENTBUFFER_HPP

#include "glad/glad.h"

struct ElementBuffer{
private:
    GLuint id;
public:
    ElementBuffer(unsigned size, GLuint* data);
    ~ElementBuffer();
    void bind();
    void unbind();
    void uploadData(unsigned size, GLuint* data);
};

#endif //PENGUENGINE_ELEMENTBUFFER_HPP
