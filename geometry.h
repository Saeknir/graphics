#ifndef GEOMETRY_FILE
#define GEOMETRY_FILE
//GL Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 rotate(float);
glm::mat4 orthographicMatrix(float, float);
glm::mat4 perspectiveMatrix(float, float, float);

#endif
