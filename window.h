#ifndef WINDOW_FILE
#define WINDOW_FILE
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <map>
#include <fstream>
#include <iostream>
#include <string>

const static int DEFAULT_HEIGHT = 480;
const static int DEFAULT_WIDTH = 640;

extern GLFWwindow* window;
void createWindow(int, int);
void createWindow();
void initialize();
#endif
