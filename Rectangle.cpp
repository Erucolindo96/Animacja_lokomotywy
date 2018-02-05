#include "Rectangle.h"



Rectangle::Rectangle(): Actor()
{}


Rectangle::Rectangle(const GLfloat x_length, const GLfloat z_length, const GLfloat height, const std::string & texture_path): Actor()
{
	setTextureFromFile(texture_path);
	verts_.emplace_back(glm::vec3(0.5 * x_length, 0.5 * height, 0.5 * z_length), glm::vec3(0, 0, 1), glm::vec2(0, 0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, 0.5 * height, 0.5 * z_length), glm::vec3(0, 0, 1), glm::vec2(1.0, 0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, 0.5 *height, -0.5 * z_length), glm::vec3(0, 0, 1), glm::vec2(0, 1.0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, 0.5 * height, -0.5 * z_length), glm::vec3(0, 0, 1), glm::vec2(1.0, 1.0));
	indices_ = { 0,1,3,  1, 2, 3 };

	bindVertexAndIndices();
}

Rectangle::Rectangle(const Rectangle &other): Actor(other)
{}

Rectangle::~Rectangle()
{
}

std::unique_ptr<Actor> Rectangle::clone() const
{
	return std::unique_ptr<Actor>(new Rectangle(*this));
}
