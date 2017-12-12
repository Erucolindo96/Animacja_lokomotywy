#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <GLFW\glfw3.h>
#include <SOIL.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include "ShaderCompilationError.h"
class Shader
{
private:
	GLuint shader_id_;
public:
	Shader();
	Shader(const char *vertexPath, const char *fragmentPath);
	std::string readShaderCode(const char* shaderPath);
	GLuint compileShader(const char *shaderCode, GLenum shaderType);
	GLuint GetShaderId() { return shader_id_; }
	void Use() { glUseProgram(GetShaderId()); }
	~Shader();
};

