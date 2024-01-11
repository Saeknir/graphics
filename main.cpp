#include "main.h"

Primitive::Primitive(){
	this->vertices = {
		//Position		//texture Coordinates
		0.5f, 0.5f, 0.0f,	1.0f, 1.0f, 
		0.5f, -0.5f, 0.0f,	1.0f, 0.0f, 
		-0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 
		0.0f, 0.5f, 0.0f,	0.0f, 1.0f	
	};
}

std::vector<float> Primitive::getVertices(){
	return this->vertices;
}

void Primitive::setVertices(std::vector<float> newVert){
	this->vertices = newVert;
}

unsigned int Primitive::getTexture(){
	return this->texture;
}

void Primitive::setTexture(unsigned int newTexture){
	this->texture = newTexture;
}

int main(){
	Primitive mainPrim;
	unsigned int vertexBuffer;
	unsigned int vertexArray;
	unsigned int shaderProgram;
	GLFWwindow* window;
	
	if(!glfwInit())
		return -1;
	window = initializeWindow();
	GLenum err = glewInit();
	if(GLEW_OK != err){
		std::cout << "Error: GLEW failed to initialize.";
		return -1;
	}
	vertexBuffer = initializeVertexBuffer(); 
	shaderProgram = initializeShaderProgram();
	vertexArray = initializeVertexArray(vertexBuffer);
	bindVertexArray(vertexArray, vertexBuffer);	
	glBufferData(GL_ARRAY_BUFFER, mainPrim.getVertices().size() * sizeof(GLfloat), static_cast<void*>(mainPrim.getVertices().data()), GL_STATIC_DRAW);
	glUseProgram(shaderProgram);
	if(!window){
		std::cout << "Window not initialized";
		glfwTerminate();
		return -1;
	}
	while(!glfwWindowShouldClose(window)){	
		frameRefresh(mainPrim.getVertices());
		glfwSwapBuffers(window);
	
		glfwPollEvents();	
	}
	return 0;
}
