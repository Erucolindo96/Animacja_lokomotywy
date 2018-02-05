#include "Box.h"



Box::Box():Actor()
{

}

Box::Box(const Box & other): Actor(other)
{
}

Box & Box::operator=(const Box & other)
{
	Actor::operator=(other);
	return *this;
}



Box::Box(const GLfloat x_length, const GLfloat y_length, const GLfloat z_length, const std::string & texture_path):Actor()
{
	countAndSetVertsAndIndices(x_length, y_length, z_length);
	setTextureFromFile(texture_path);
	bindVertexAndIndices();
}


std::unique_ptr<Actor> Box::clone() const
{
	return std::unique_ptr<Actor>(new Box(*this));
}

Box::~Box()
{}

void Box::setTextureCoordinate()
{
	verts_[0].textCoord_ = { 0.0, 0.0 };
}


void Box::countAndSetVertsAndIndices(const GLfloat x_length, const GLfloat y_length, const GLfloat z_length)
{
	indices_ = { 0, 1, 2, 2, 1, 3, 4, 5, 6, 6, 5, 7, 8, 9, 10, 10, 9, 11, 12, 13, 14, 14, 13, 15, 16, 17,
		18, 18, 17, 19, 20, 21, 22, 22, 21, 23, };
	verts_.emplace_back(glm::vec3(-0.5 * x_length, -0.5 * y_length, 0.5 * z_length), glm::vec3(0, 0, 1), glm::vec2(0, 0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, -0.5 * y_length, 0.5 * z_length), glm::vec3(0, 0, 1), glm::vec2(1.0, 0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, 0.5 * y_length, 0.5 * z_length), glm::vec3(0, 0, 1), glm::vec2(0, 1.0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, 0.5 * y_length, 0.5 * z_length), glm::vec3(0, 0, 1), glm::vec2(1.0, 1.0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, 0.5 * y_length, -0.5 * z_length), glm::vec3(0, 0, -1), glm::vec2(1.0, 1.0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, 0.5 * y_length, -0.5 * z_length), glm::vec3(0, 0, -1), glm::vec2(0, 1.0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, -0.5 * y_length, -0.5 * z_length), glm::vec3(0, 0, -1), glm::vec2(1.0, 0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, -0.5 * y_length, -0.5 * z_length), glm::vec3(0, 0, -1), glm::vec2(0, 0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, 0.5 * y_length, 0.5 * z_length), glm::vec3(0, 1, 0), glm::vec2(0, 0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, 0.5 * y_length, 0.5 * z_length), glm::vec3(0, 1, 0), glm::vec2(1.0, 0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, 0.5 * y_length, -0.5 *z_length), glm::vec3(0, 1, 0), glm::vec2(0, 1.0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, 0.5 * y_length, -0.5 * z_length), glm::vec3(0, 1, 0), glm::vec2(1.0, 1.0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, -0.5 * y_length, -0.5 * z_length), glm::vec3(0, -1, 0), glm::vec2(0, 0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, -0.5 * y_length, -0.5 *z_length), glm::vec3(0, -1, 0), glm::vec2(1.0, 0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, -0.5 * y_length, 0.5 *z_length), glm::vec3(0, -1, 0), glm::vec2(0, 1.0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, -0.5 * y_length, 0.5 *z_length), glm::vec3(0, -1, 0), glm::vec2(1.0, 1.0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, -0.5 * y_length, 0.5 *z_length), glm::vec3(1, 0, 0), glm::vec2(0, 0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, -0.5 * y_length, -0.5 *z_length), glm::vec3(1, 0, 0), glm::vec2(1.0, 0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, 0.5 * y_length, 0.5 *z_length), glm::vec3(1, 0, 0), glm::vec2(0, 1.0));
	verts_.emplace_back(glm::vec3(0.5 * x_length, 0.5 * y_length, -0.5 *z_length), glm::vec3(1, 0, 0), glm::vec2(1.0, 1.0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, -0.5 * y_length, -0.5 *z_length), glm::vec3(-1, 0, 0), glm::vec2(0, 0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, -0.5 * y_length, 0.5 *z_length), glm::vec3(-1, 0, 0), glm::vec2(1.0, 0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, 0.5 * y_length, -0.5 *z_length), glm::vec3(-1, 0, 0), glm::vec2(0, 1.0));
	verts_.emplace_back(glm::vec3(-0.5 * x_length, 0.5 * y_length, 0.5 *z_length), glm::vec3(-1, 0, 0), glm::vec2(1.0, 1.0));

}


