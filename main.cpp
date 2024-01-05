#include "main.h"

int main(){
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	unsigned int vertexBuffer;
	unsigned int fragmentShader;
	unsigned int vertexShader;
	unsigned int geometryShader;
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
	fragmentShader = initializeFragmentShader();
	vertexShader = initializeVertexShader();

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
