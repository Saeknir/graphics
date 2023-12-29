cmake_minimum_required(VERSION 3.11)

project(graphics)

add_executable(${PROJECT_NAME}
	main.cpp
	window.cpp
	)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)
