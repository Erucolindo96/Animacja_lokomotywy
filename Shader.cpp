#include "Shader.h"



Shader::Shader()
{

}


Shader::~Shader()
{
}

Shader::Shader(const char * vertexPath, const char * fragmentPath)
{
	std::string vertex_code = readShaderCode(vertexPath);
	GLuint vertex_id = compileShader(vertex_code.c_str(), GL_VERTEX_SHADER);
	std::string fragment_code = readShaderCode(fragmentPath);
	GLuint fragment_id = compileShader(fragment_code.c_str(), GL_FRAGMENT_SHADER);

	shader_id_ = glCreateProgram();
	glAttachShader(shader_id_, vertex_id);
	glAttachShader(shader_id_, fragment_id);
	glLinkProgram(shader_id_);

	GLint success=1;
	glGetProgramiv(shader_id_, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[4096];
		glGetShaderInfoLog(shader_id_, sizeof(infoLog), NULL, infoLog);
		std::string msg = std::string("Shader::Linker error: \n") + infoLog;
		throw ShaderCompilationError(msg);
	}
	//glDeleteShader(vertex_id);
	glDeleteShader(fragment_id);
}

std::string Shader::readShaderCode(const char * shaderPath)
{
	std::ifstream shader_file;
	std::stringstream shader_stream;

	shader_file.exceptions(std::ifstream::badbit);
	shader_file.open(shaderPath);
	shader_stream << shader_file.rdbuf();
	shader_file.close();
	return shader_stream.str();
}

GLuint Shader::compileShader(const char * shaderCode, GLenum shaderType)
{
	GLuint shaderId = glCreateShader(shaderType);
	glShaderSource(shaderId, 1, &shaderCode, NULL);
	glCompileShader(shaderId);

	GLint success = 0;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[1024];
		glGetShaderInfoLog(shaderId, sizeof(infoLog), NULL, infoLog);
		std::string msg = std::string("Shader::Compilation error: \n") + infoLog;
		throw ShaderCompilationError(msg);
	}
	return shaderId;
}
