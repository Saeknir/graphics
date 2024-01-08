#ifndef SHADER_FILE
#define SHADER_FILE
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

const static unsigned int LOG_CHAR_SIZE = 512;

unsigned int initializeVertexShader();
unsigned int initializeFragmentShader();
unsigned int initializeVertexBuffer();
unsigned int initializeShaderProgram();
#endif
