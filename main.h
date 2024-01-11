#ifndef MAIN_FILE
#define MAIN_FILE
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "interface.h"
#include "window.h"
#include "rendering.h"
#include "shaders.h"
#include "geometry.h"

GLFWwindow* window;

class Primitive{
	private:
		unsigned int texture;
		std::vector<float>vertices;
	public: 
		Primitive();
		void setVertices(std::vector<float>);
		std::vector<float> getVertices();
		void setTexture(unsigned int);
		unsigned int getTexture();
};

#endif
