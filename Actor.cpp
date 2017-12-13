#include "Actor.h"



Actor::Actor()
{
	initBuffers();
}

void Actor::setPosition(glm::vec3 position)
{
	position_ = position;
}

glm::vec3 Actor::getPosition() const
{
	return glm::vec3(position_);
}

void Actor::setRotation(glm::vec3 rotation)
{
	rotation_ = rotation;
}

glm::vec3 Actor::getRotation() const
{
	return glm::vec3(rotation_);
}

void Actor::draw() const
{

	glBindVertexArray(VAO_);
	glDrawElements(GL_TRIANGLES, (GLsizei)indices_.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


Actor::~Actor()
{
	glDeleteVertexArrays(1, &VAO_);
	glDeleteBuffers(1, &VBO_);
	glDeleteBuffers(1, &EBO_);
}

void Actor::setShaderId(GLuint shader_id)
{
	shader_id_ = shader_id;
}

GLuint Actor::getShaderId() const
{
	return shader_id_;
}

void Actor::setVertices(const std::vector<Vertex> &verts)
{
	verts_ = verts;
}

std::vector<Vertex> Actor::getVertices() const
{
	return std::vector<Vertex>(verts_);
}

void Actor::setIndices(const std::vector<GLuint> &indices)
{
	indices_ = indices;
}

std::vector<GLuint> Actor::getIndices() const
{
	return std::vector<GLuint>(indices_);
}

void Actor::initBuffers()
{
	glGenVertexArrays(1, &VAO_);
	glGenBuffers(1, &VBO_);
	glGenBuffers(1, &EBO_);
}

void Actor::bindVertexAndIndices()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO_);
	glBindVertexArray(VAO_);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);

	glBufferData(GL_ARRAY_BUFFER, verts_.size() * sizeof(Vertex), &verts_[0], GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(GLuint), &indices_[0], GL_STATIC_DRAW);
	//miejsce w pamieci wspolrzednych
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	//normalnych
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal_));
	//tekstury
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textCoord_));
	//koloru
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color_));
	
	glBindVertexArray(0);

}

Vertex::Vertex()
{

}

Vertex::Vertex(const Vertex & other): position_(other.position_), normal_(other.normal_), textCoord_(other.textCoord_), color_(other.color_)
{}
