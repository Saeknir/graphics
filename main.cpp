#include "main.h"

Primitive::Primitive(){
	this->vertices = {
		//Position		//color			//texture Coordinates
		0.5f, 0.5f, 0.0f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f, 		
		0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f, 	1.0f, 0.0f, 
		-0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f, 
		-0.5f, 0.5f, 0.0f,	1.0f, 1.0f, 0.0f,	0.0f, 1.0f,
	};
	this->indices = {
		0, 1, 3, 
		1, 2, 3
	};
}

std::vector<float> Primitive::getVertices(){
	return this->vertices;
}

void Primitive::setVertices(std::vector<float> newVert){
	this->vertices = newVert;
}

std::vector<unsigned int> Primitive::getIndices(){
	return this->indices;
}

void Primitive::setIndices(std::vector<unsigned int> newIndex){
	this->indices = newIndex;
}

Texture Primitive::getTexture(){
	return this->texture;
}

/*void Primitive::setTexture(Texture newTexture){
	this->texture = newTexture;
}*/

void vertexAttributes(){
	//Position Attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//Color Attributes
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	//Texture Position Attributes
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(2);
}

int main(){
	Primitive mainPrim;
	unsigned int elementBuffer;
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
	elementBuffer = initializeElementBuffer();
	shaderProgram = initializeShaderProgram();
	vertexArray = initializeVertexArray(vertexBuffer);
	bindVertexArray(vertexArray, vertexBuffer);	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mainPrim.getIndices().size()*sizeof(unsigned int), static_cast<void*>(mainPrim.getIndices().data()), GL_STATIC_DRAW);
	vertexAttributes();
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glBufferData(GL_ARRAY_BUFFER, mainPrim.getVertices().size() * sizeof(GLfloat), static_cast<void*>(mainPrim.getVertices().data()), GL_STATIC_DRAW);
	//glEnableVertexAttribArray(0);
	glUseProgram(shaderProgram);
	//initializeTextures();
	if(!window){
		std::cout << "Window not initialized";
		glfwTerminate();
		return -1;
	}
	while(!glfwWindowShouldClose(window)){	
		frameRefresh(shaderProgram, vertexArray, elementBuffer);
		glfwSwapBuffers(window);
	
		glfwPollEvents();	
	}
	return 0;
}
