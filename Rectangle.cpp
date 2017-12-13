#include "Rectangle.h"



Rectangle::Rectangle(): Actor()
{}


Rectangle::Rectangle(std::vector<Vertex> verts) : Actor()
{
	verts_ = verts;
	indices_ = { 0,1,3,  1, 2, 3 };
	bindVertexAndIndices();
}

Rectangle::~Rectangle()
{
}
