#ifndef WINDOW_FILE
#define WINDOW_FILE
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <map>
#include <fstream>
#include <iostream>
#include <string>

#include "camera.h"

const static int DEFAULT_HEIGHT = 480;
const static int DEFAULT_WIDTH = 640;
const static float DEFAULT_SPEED = 0.05;

GLFWwindow* createWindow(int, int);
GLFWwindow* createWindow();
GLFWwindow* initializeWindow();

void processInput(GLFWwindow*, float, Camera*);
void processInput(GLFWwindow*, Camera*);

#endif
