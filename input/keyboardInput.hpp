//
// Created by nicol on 27/11/2022.
//
#include <GLFW/glfw3.h>

#ifndef PENGUENGINE_KEYBOARDINPUT_H
#define PENGUENGINE_KEYBOARDINPUT_H

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int initKeyboardInputListener(GLFWwindow* windowPtr);

#endif //PENGUENGINE_KEYBOARDINPUT_H
