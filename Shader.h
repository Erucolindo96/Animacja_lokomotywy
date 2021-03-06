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
	Shader(GLuint other_shader_id);
	Shader(const char *vertexPath, const char *fragmentPath);
	std::string readShaderCode(const char* shaderPath);
	GLuint compileShader(const char *shaderCode, GLenum shaderType);
	GLuint GetShaderId()const { return shader_id_; };
	void Use()const { glUseProgram(GetShaderId()); }

	GLuint getProjectionId()const;
	GLuint getViewId()const;
	GLuint getModelId()const;
	~Shader();
};

