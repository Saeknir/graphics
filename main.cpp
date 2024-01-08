#include "main.h"

int main(){
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glUseProgram(shaderProgram);
	if(!window){
		std::cout << "Window not initialized";
		glfwTerminate();
		return -1;
	}
	while(!glfwWindowShouldClose(window)){	
		frameRefresh(vertices);
		glfwSwapBuffers(window);
	
		glfwPollEvents();	
	}
	return 0;
}
