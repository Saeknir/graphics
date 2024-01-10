#ifndef SHADER_FILE
#define SHADER_FILE
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

const static unsigned int LOG_CHAR_SIZE = 512;

unsigned int initializeVertexShader();
unsigned int initializeFragmentShader();
unsigned int initializeVertexBuffer();
unsigned int initializeShaderProgram();
void bindVertexArray(unsigned int, unsigned int);
unsigned int initializeVertexArray(unsigned int);
#endif
