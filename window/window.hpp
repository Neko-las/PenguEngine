//
// Created by nicol on 27/11/2022.
//

#include <GLFW/glfw3.h>



#ifndef PENGUENGINE_WINDOW_HPP
#define PENGUENGINE_WINDOW_HPP


void destroyWindow(GLFWwindow* windowPtr);

GLFWwindow* initWindow();

GLFWwindow* getWindowPointer();

#endif //PENGUENGINE_WINDOW_HPP
