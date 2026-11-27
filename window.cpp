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

//Input class handles variables required for keyboard and mouse input.
void Input::setLastX(float newX){
	this->lastX = newX;
}

float Input::getLastX(){
	return lastX;
}

void Input::setLastY(float newY){
	this->lastY = newY;
}

float Input::getLastY(){
	return lastY;
}


//Create the initial window
GLFWwindow* createWindow(int width, int height){
	GLFWwindow* window = glfwCreateWindow(width, height, "Frankengraphics", NULL, NULL);
	Input* inputHandler = new Input;
	glfwSetWindowUserPointer(window, inputHandler);
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
		std::cout << "Config not found" << std::endl;
	}
	return createWindow(width, height);
}

void processInput(GLFWwindow* window, float speed, Camera* camera){
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->setPos(camera->getPos() - camera->getDirection()*speed);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->setPos(camera->getPos() + camera->getDirection()*speed);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->setPos(camera->getPos() - glm::normalize(glm::cross(camera->getDirection(), camera->getUp()))*speed);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->setPos(camera->getPos() + glm::normalize(glm::cross(camera->getDirection(), camera->getUp()))*speed);

}

void processInput(GLFWwindow* window, Camera* camera){
	processInput(window, DEFAULT_SPEED, camera);
}

void mouseCallback(GLFWwindow* window, double xPos, double yPos){
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	Input* inputHandler = static_cast<Input*>(glfwGetWindowUserPointer(window));
	//float hCenter = width/2;
	//float vCenter = height/2;
	
	float sensitivity = 0.1f;
	float xOffset = xPos - inputHandler->getLastX();
	float yOffset = inputHandler->getLastY() - yPos;
	xOffset *= sensitivity;
	yOffset *= sensitivity;
	inputHandler->setLastX(xPos);
	inputHandler->setLastY(yPos);
	std::cout << "Offsets: "  << xOffset << " " << yOffset << std::endl;
	activeCamera->setYaw(activeCamera->getYaw() + xOffset);
	activeCamera->setPitch(activeCamera->getPitch() + yOffset);
	glm::vec3 direction;
	direction.x = cos(glm::radians(activeCamera->getYaw())) * cos(glm::radians(activeCamera->getPitch()));
	direction.y = sin(glm::radians(activeCamera->getPitch()));
	direction.z = sin(glm::radians(activeCamera->getYaw())) * cos(glm::radians(activeCamera->getPitch()));
	activeCamera->setDirection(direction);
	std::cout << "target: " << activeCamera->getTarget().x+activeCamera->getPos().x << "," << activeCamera->getTarget().y+activeCamera->getPos().y << "," << activeCamera->getTarget().z+activeCamera->getPos().z << "Direction: "  << std::endl;	
}
