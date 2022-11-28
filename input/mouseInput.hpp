//
// Created by nicol on 27/11/2022.
//
#include <GLFW/glfw3.h>

#ifndef PENGUENGINE_MOUSEINPUT_H
#define PENGUENGINE_MOUSEINPUT_H

static void cursor_position_callback(GLFWwindow* window,double xPos,double yPos);

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

int initMouseInputListener(GLFWwindow* windowPtr);

#endif //PENGUENGINE_MOUSEINPUT_H
