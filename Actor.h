#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <GLFW\glfw3.h>
#include <SOIL.h>

#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

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

	std::vector<GLuint> getIndices()const;
	std::vector<Vertex> getVertices()const;

	GLuint getShaderId()const;
	void setShaderId(GLuint shader_id);
	/**
		Metoda rysuje na scenie, za pomoc¹ podanego shadera, wierzcho³ki które zawiera klasa jako trójk¹ty
	*/
	virtual void draw()const;
	virtual std::unique_ptr<Actor> clone()const = 0;
	virtual ~Actor();


protected:
	Actor();
	Actor(const Actor &other);
	std::vector<Vertex> verts_;
	std::vector<GLuint> indices_;
	GLuint shader_id_;
	GLuint VBO_, VAO_, EBO_;
	glm::vec3 position_;
	glm::vec3 rotation_;

	void setVertices(const std::vector<Vertex> &verts);
	void setIndices(const std::vector<GLuint> &indices);
	/**
		Metoda twrozy bufory OpenGla
	*/
	void initBuffers();
	/**
		Metoda tworzy bufory OpenGla 
	*/
	
	void bindVertexAndIndices();
	/**
		Metoda dolacza  do buforow OpenGla wartosci pol klasy
		Nalezy ja zawolac w konstruktorach klas pochodnych gdy zostana juz dodane wartosci pol klasy
	*/
	virtual void countAndSetVertsAndIndices();


};

