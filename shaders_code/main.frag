#version 330 core

in vec3 inColor;
out vec4 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
  
void main(void)
{
    color = vec4(inColor, 1.0f);
}