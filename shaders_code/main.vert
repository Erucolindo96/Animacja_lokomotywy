#version 330 core
layout (location = 0) in vec3 vertex_pos; 
layout (location = 2) in vec2 Tex_coord;
out vec2 oTex_coord;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
  gl_Position =  projection * view * model * vec4(vertex_pos, 1.0f);
	
  oTex_coord = Tex_coord;
}

