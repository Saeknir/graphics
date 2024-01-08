#include "window.h"

std::map<std::string, GLuint> windowMap = {
	{"antialiasing", GLFW_SAMPLES},
	{"doublebuffer", GLFW_DOUBLEBUFFER},
	{"resizable", GLFW_RESIZABLE}
};

std::map<std::string, GLuint> contextMap = {
	{"opengl", GLFW_CONTEXT_VERSION_MAJOR},
	{"forwardcompat", GLFW_OPENGL_FORWARD_COMPAT},
	{"openglprofile", GLFW_OPENGL_PROFILE},
	{"doublebuffer", GLFW_DOUBLEBUFFER}
};

std::map<std::string, GLuint> valueMap = {
	{"core", GLFW_OPENGL_CORE_PROFILE},
	{"TRUE", GL_TRUE},
	{"FALSE", GL_FALSE}
};
			
//Initialize the window
GLFWwindow* createWindow(int width, int height){
	GLFWwindow* window = glfwCreateWindow(width, height, "Frankengraphics", NULL, NULL);
	if(window == NULL){
		std::cout << "failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glViewport(0, 0, width, height);
	return window;
}

GLFWwindow* createWindow(){
	return createWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT);
}

//Reads in the settings from the config, writing them to a context map for further initializing values.
//Should only be done once, when application starts.
GLFWwindow* initializeWindow(){
	int width = DEFAULT_WIDTH;
       	int height = DEFAULT_HEIGHT;	
	std::string filename = "./config.ini";
	std::ifstream config(filename.c_str());
	if(config.is_open()){
		std::string line;
		while(getline(config, line)){
			
			int delimPos = line.find('=');
			int endPos = line.length()-1;
			std::string key = line.substr(0, delimPos);
			std::string value = line.substr(delimPos+1, endPos);
		if(key=="opengl"){ 
				//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, (int)value.front());
				//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, (int)value.back());
		}else if(key == "width"){
			       width = std::stoi(value);	       
				break;
		}else if(key == "height"){ 
				height = std::stoi(value);
				break;
		}else{
				if(valueMap.count(value)==1){
					//glfwWindowHint(windowMap[key], valueMap[value]);
				}else{
					//glfwWindowHint(windowMap[key], std::stoi(value));
				}
		}
		}
		config.close();
		/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/
	}else{
		std::cout << "Config not found";
	}
	return createWindow(width, height);
}
