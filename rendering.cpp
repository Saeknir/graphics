#include "rendering.h"

void bindVertexArray(){

}

//Operations to reset the rendered window for each frame.
void frameRefresh(unsigned int shaderProgram, unsigned int vertexArray, unsigned int indexArray, unsigned int texture, Camera viewCamera){
	glUseProgram(shaderProgram);
	glBindVertexArray(vertexArray);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	float time = glfwGetTime();
	float greenValue = sin(time)/2.0f+0.5f;
	int vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColor");
	glm::mat4 transform = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	projection = perspectiveMatrix(45.0f, 800.0f, 600.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	//Temporary camera testing
	viewCamera.setPos(glm::vec3(sin(glfwGetTime()*10.0f), 0.0f, cos(glfwGetTime()*10.0f)));
	view = viewCamera.getView();
	int modelLoc = glGetUniformLocation(shaderProgram, "model");
	int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	int viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
