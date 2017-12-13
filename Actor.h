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
	glm::vec3 position_;//nie wiem czy nie powinny byc we wsporzednych znormalizowanych
	glm::vec3 normal_;//jak wyzej
	glm::vec2 textCoord_;
	glm::vec3 color_;

	Vertex();
	Vertex(const Vertex &other);
	Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textCoord, glm::vec3 color) : position_(position), normal_(normal), textCoord_(textCoord), color_(color) {}
};

class Actor
{
public:

	void setPosition(glm::vec3 position);
	glm::vec3 getPosition()const;
	void setRotation(glm::vec3 rotation);
	glm::vec3 getRotation()const;

	virtual void draw()const;
	virtual ~Actor();


protected:
	Actor();
	std::vector<Vertex> verts_;
	std::vector<GLuint> indices_;
	GLuint shader_id_;
	GLuint VBO_, VAO_, EBO_;
	glm::vec3 position_;
	glm::vec3 rotation_;

	//gettery i settery
	void setShaderId(GLuint shader_id);
	GLuint getShaderId()const;

	void setVertices(const std::vector<Vertex> &verts);
	std::vector<Vertex> getVertices()const;

	void setIndices(const std::vector<GLuint> &indices);
	std::vector<GLuint> getIndices()const;

	void initBuffers();
	void bindVertexAndIndices();


};

