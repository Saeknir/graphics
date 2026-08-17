#ifndef MAIN_FILE
#define MAIN_FILE
//OpenGL extension Wrangler
#include <GL/glew.h>
#include <GL/gl.h>
//OpenGL Window library
#include <GLFW/glfw3.h>
//openGL mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//Standard C++ Libaries
#include <iostream>
#include <vector>
#include <math.h>

#include "interface.h"
#include "window.h"
#include "rendering.h"
#include "shaders.h"
#include "textures.h"
#include "geometry.h"

GLFWwindow* window;

class Primitive{
	private:
		Texture texture;
		std::vector<float>vertices;
		std::vector<unsigned int> indices;
	public: 
		Primitive();
		void setVertices(std::vector<float>);
		std::vector<float> getVertices();
		void setIndices(std::vector<unsigned int>);
		std::vector<unsigned int> getIndices();
		void setTexture(unsigned int, unsigned int, unsigned int, unsigned int);
		void setTexture(Texture);
		Texture& getTexture();
};

#endif
