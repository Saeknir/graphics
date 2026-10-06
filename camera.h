#ifndef CAMERA_FILE
#define CAMERA_FILE
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
//openGL Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera{
	private:
		glm::vec3 pos;
		glm::vec3 target;
//		glm::vec3 camUp;
//		glm::vec3 camFront;
	public:
		Camera();
		glm::vec3 getPos();
		void setPos(glm::vec3);
		glm::vec3 getTarget();
		void setTarget(glm::vec3);
		glm::mat4 getView();
};

#endif
