#include "textures.h"

void initializeTextures(){
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void loadTexture(std::string fileName){
	unsigned int texture;
	int width, height, nbrChannels;
	unsigned char* data;
	glGenTextures(1, &texture);
	data = stbi_load(fileName, &width, &height, &nbrChannels, 0);
	if(data){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}else{
		std::cout << "Failed to load texture: " << fileName;
	}
	stbi_image_free(data);
}
