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

void Primitive::setTexture(Texture newTexture){
	this->texture = newTexture;
}

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
	std::vector<Primitive> primitiveList;
	Primitive mainPrim;
	primitiveList.push_back(mainPrim);
	std::vector<float> masterVerticesList;
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
	//initialize settings and buffers.
	vertexBuffer = initializeVertexBuffer(); 
	elementBuffer = initializeElementBuffer();
	shaderProgram = initializeShaderProgram();
	vertexArray = initializeVertexArray(vertexBuffer);
	initializeTextures();
	bindVertexArray(vertexArray, vertexBuffer);	
	//vertexAttributes();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	//Iterate through the list of primitives, then append the vertices into a master vertices list.
	for(const auto& i : primitiveList){
		
		//for(int v = 0; v < primitiveList[i].getVertices()size(); ++v){
		//	masterVerticesList.push_back(v);
		//}
	
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mainPrim.getIndices().size()*sizeof(unsigned int), static_cast<void*>(mainPrim.getIndices().data()), GL_STATIC_DRAW);
	//vertexAttributes();
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
		glBufferData(GL_ARRAY_BUFFER, mainPrim.getVertices().size() * sizeof(GLfloat), static_cast<void*>(mainPrim.getVertices().data()), GL_STATIC_DRAW);
	}
		//glEnableVertexAttribArray(2);
	vertexAttributes();
	glUseProgram(shaderProgram);
	mainPrim.getTexture().setTextureID(loadTexture("tex.jpg"));
	if(!window){
		std::cout << "Window not initialized";
		glfwTerminate();
		return -1;
	}
	while(!glfwWindowShouldClose(window)){	
		frameRefresh(shaderProgram, vertexArray, elementBuffer, mainPrim.getTexture().getTextureID());
		glfwSwapBuffers(window);
	
		glfwPollEvents();	
	}
	return 0;
}
