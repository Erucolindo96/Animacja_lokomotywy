#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <GLFW\glfw3.h>
#include <SOIL.h>

#include <vector>
#include <stdexcept>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textCoord;

	Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textCoord) : position(position), normal(normal), textCoord(textCoord) {}
};

class Actor
{
public:
	Actor();
	void setPosition(glm::vec4 position);
	glm::vec4 getPosition()const;

	void draw()const;
	virtual ~Actor();


protected:
	std::vector<Vertex> verts_;
	std::vector<GLuint> indices_;
	GLuint shader_id_;
	GLuint VBO_, VAO_, EBO_;
	glm::vec4 position_;

	//gettery i settery
	void setShaderId(GLuint shader_id);
	GLuint getShaderId()const;

	void setVertices(std::vector<Vertex> verts);
	std::vector<Vertex> getVertices()const;

	void setIndices(std::vector<GLuint> indices);
	std::vector<GLuint> getIndices()const;

};

