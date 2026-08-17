#include "rendering.h"

void bindVertexArray(){

}

//Operations to reset the rendered window for each frame.
void frameRefresh(unsigned int shaderProgram, unsigned int vertexArray, unsigned int indexArray, unsigned int texture){
	glUseProgram(shaderProgram);
	glBindVertexArray(vertexArray);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	float time = glfwGetTime();
	float greenValue = sin(time)/2.0f+0.5f;
	int vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColor");
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
