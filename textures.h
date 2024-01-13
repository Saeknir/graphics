#ifndef TEXTURE_FILE
#define TEXTURE_FILE

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Texture{
	private:
		unsigned int width;
		unsigned int height;
		unsigned int nbrChannels;
		unsigned int textureID;
	public:
		void setWidth(unsigned int);
		unsigned int getWidth();
		void setHeight(unsigned int);
		unsigned int getHeight();
		void setChannels(unsigned int);
		unsigned int getChannels();
		void setTextureID(unsigned int);
		unsigned int getTextureID();
};

void initializeTextures();

#endif
