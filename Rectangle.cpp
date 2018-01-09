#include "Rectangle.h"



Rectangle::Rectangle(): Actor()
{}


Rectangle::Rectangle(std::vector<Vertex> verts) : Actor()
{
	verts_ = verts;
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
