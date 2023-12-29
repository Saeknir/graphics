#include "main.h"

int main(){
	if(!glfwInit())
		return -1;
	createWindow();
	if(!window){
		std::cout << "Window not initialized";
		glfwTerminate();
		return -1;
	}
	while(!glfwWindowShouldClose(window)){
	glfwSwapBuffers(window);
	glfwPollEvents();	
	}
	return 0;
}
