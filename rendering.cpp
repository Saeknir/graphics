#include "rendering.h"

void bindVertexArray(){

}

//Operations to reset the rendered window for each frame.
void frameRefresh(float vertices[]){
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
