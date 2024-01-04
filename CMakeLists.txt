cmake_minimum_required(VERSION 3.11)

project(graphics)

add_executable(${PROJECT_NAME}
	window.cpp
	rendering.cpp
	shaders.cpp
	main.cpp
	)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} GLEW::GLEW glfw)	
