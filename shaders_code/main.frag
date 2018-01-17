#version 330 core

in vec2 oTex_coord;
out vec4 FragColor;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;
  
  uniform sampler2D ourTexture;

void main()
{
   FragColor = texture(ourTexture, oTex_coord);
}