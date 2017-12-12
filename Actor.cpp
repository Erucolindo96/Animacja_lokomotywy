#include "Actor.h"



Actor::Actor()
{
	throw std::runtime_error("TODO");
}

void Actor::setPosition(glm::vec4 position)
{
	throw std::runtime_error("TODO");
}

glm::vec4 Actor::getPosition() const
{
	throw std::runtime_error("TODO");
	return glm::vec4();
}

void Actor::draw() const
{
	throw std::runtime_error("TODO");
}


Actor::~Actor()
{
}

void Actor::setShaderId(GLuint shader_id)
{
}

GLuint Actor::getShaderId() const
{
	return 0;
}

void Actor::setVertices(std::vector<Vertex> verts)
{
}

std::vector<Vertex> Actor::getVertices() const
{
	return std::vector<Vertex>();
}

void Actor::setIndices(std::vector<GLuint> indices)
{
}

std::vector<GLuint> Actor::getIndices() const
{
	return std::vector<GLuint>();
}
