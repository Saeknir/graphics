#include "camera.h"

Camera::Camera(){
	this->pos = glm::vec3(0.0f, 0.0f, 1.0f);
	this->target = glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::vec3 Camera::getPos(){
	return this->pos;
}

void Camera::setPos(glm::vec3 newPos){
	this->pos = newPos;
}

glm::vec3 Camera::getTarget(){
	return this->target;
}

void Camera::setTarget(glm::vec3 newTarget){
	this->target = newTarget;
}

glm::mat4 Camera::getView(){
	glm::vec3 cameraDirection = glm::normalize(getPos()-getTarget());
	//Default view will align to a standard up direction, will implement method to accept rotation.
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	//glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection);
	//glm::vec3 CameraUp = glm::cross(cameraDirection, cameraRight);
	return glm::lookAt(getPos(), getTarget(), up);
}

