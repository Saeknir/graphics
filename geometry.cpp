#include "geometry.h"

//Creates a rotation matrix. Accepts a single float which is the number of radians to rotate.
glm::mat4 rotate(float radians){
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::rotate(transform, radians, glm::vec3(0.0, 0.0, 1.0));
	return transform;
}

//Create an orthographic matrix, accepting two floats corresponding to the width and height of the desired matrix.
//TODO: implement mathematics instead of prebuilt
glm::mat4 orthograpicMatrix(float width, float height){
	return glm::ortho(0.0f, width, 0.0f, height, 0.1f, 100.0f);
}

//Create a perspective matrix with three floats corresponding to fov, width, and height.
//TODO: implement mathematics instead of prebuilt
glm::mat4 perspectiveMatrix(float fov, float width, float height){
	return glm::perspective(glm::radians(fov), width/height, 0.1f, 100.0f);
}
