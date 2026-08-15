#version 330 core
out vec4 fragColor;

in  vec3 vertexColor;
in  vec2 textureCoord; 

uniform sampler2D ourTexture;

void main(){
	fragColor = texture(ourTexture, textureCoord);
}
