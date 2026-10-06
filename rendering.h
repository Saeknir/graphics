#ifndef RENDERING_FILE
#define RENDERING_FILE
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>
#include <cmath>

#include "geometry.h"
#include "camera.h"

void frameRefresh(unsigned int, unsigned int, unsigned int, unsigned int, Camera);

#endif
