#include "rendering.h"

void bindVertexArray(){

}

//Operations to reset the rendered window for each frame.
void frameRefresh(unsigned int shaderProgram, unsigned int vertexArray, unsigned int indexArray){
	glUseProgram(shaderProgram);
	glBindVertexArray(vertexArray);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
