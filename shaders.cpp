#include "shaders.h"


unsigned int initializeVertexShader(){
	unsigned int vertexShader;
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"	gl_position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char log[LOG_CHAR_SIZE];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(vertexShader, LOG_CHAR_SIZE, NULL, log);
		std::cout << "Error: Shader Vertex failed to compile\n" << log << std::endl;
	}
	return vertexShader;
}

unsigned int initializeFragmentShader(){
	unsigned int fragmentShader;
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main()\n"
		"{\n"
		"	fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	return fragmentShader;
}

unsigned int initializeVertexBuffer(){
	unsigned int tempVertexBuffer;
	glGenBuffers(1, &tempVertexBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, tempVertexBuffer);
	return tempVertexBuffer;
}

void createShaderProgram(){

}