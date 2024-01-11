#include "shaders.h"

std::string loadShader(std::string path, std::string shaderType){
	std::stringstream readIn;
	std::ifstream fileRead(path, std::ios::in);
	if(!fileRead.is_open()){
		std::cout << "Failed to read from shader file for: " << shaderType << std::endl;
		glfwTerminate();
	}
	readIn << fileRead.rdbuf();
	std::string file = readIn.str();
	return file;
	
}

unsigned int initializeVertexShader(){
	unsigned int vertexShader;
	const char* vertexShaderSource; 
	std::string readIn = loadShader("vertexShader.vert", "vertex");
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	vertexShaderSource = readIn.c_str();
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
	const char* fragmentShaderSource;
	std::string readIn = loadShader("fragmentShader.frag", "fragment");
        fragmentShaderSource = readIn.c_str();	
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	int success;
	char log[LOG_CHAR_SIZE];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(fragmentShader, LOG_CHAR_SIZE, NULL, log);
		std::cout << "Error: Fragment shader failed to compile\n" << log << std::endl;
	}
	return fragmentShader;
}

unsigned int initializeVertexBuffer(){
	unsigned int tempVertexBuffer;
	glGenBuffers(1, &tempVertexBuffer);
	return tempVertexBuffer;
}

unsigned int initializeVertexArray(unsigned int vertexBuffer){
	unsigned int vertexArray;	
	glGenVertexArrays(1, &vertexArray);
	return vertexArray;
}

void bindVertexArray(unsigned int vertexArray, unsigned int vertexBuffer){
	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned int initializeShaderProgram(){
	unsigned int fragmentShader;
	unsigned int vertexShader;
	unsigned int shaderProgram = glCreateProgram();
	fragmentShader = initializeFragmentShader();
	vertexShader = initializeVertexShader();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	int success;
	char log[LOG_CHAR_SIZE];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success){
		glGetProgramInfoLog(shaderProgram, LOG_CHAR_SIZE, NULL, log);
		std::cout << "Error: Failed to attach shader program\n" << log << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	return shaderProgram;
}
