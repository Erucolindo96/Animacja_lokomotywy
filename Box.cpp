#include "Box.h"



Box::Box():Actor()
{

}

Box::Box(const Box & other): Actor(other)
{
}

Box::Box(const std::vector<Vertex>& base, GLfloat height): Actor()
{
	countAndSetVertsAndIndices(base, height);
	bindVertexAndIndices();

	//throw std::runtime_error("TODO");
}


std::unique_ptr<Actor> Box::clone() const
{
	return std::unique_ptr<Actor>(new Box(*this));
}

Box::~Box()
{}

void Box::countAndSetVertsAndIndices(const std::vector<Vertex> &base, const GLfloat height)
{
	verts_ = base;

	glm::vec3 normal = glm::triangleNormal(base[0].position_, base[1].position_, base[2].position_);
	glm::vec3 up_base[4];
	//tworzymy wektor normalny o dlugosci heigth
	normal *= height;
	normal /= normal.length();

	for (int i = 0; i < 4; ++i)// 4 - to ilosc wierzcholkow podstawy
	{//przesuwamy podstawe o wektor normalny o dlugosci height
		up_base[i] = base[i].position_ + normal;
	}
	Vertex v(base[0]); //kopiujemy inne parametry np teksture
	
	for (int i = 0; i < 4; ++i)
	{
		v.position_ = up_base[i];
		verts_.push_back(v);
	}
	//mamy wierzcholki - teraz kolejnosc renderingu
	indices_ = {0, 2 , 1,  0 ,3, 2, //podstawa dolna
				1, 2, 6,   6, 5, 1, // prawa
				0, 7, 3,   0, 4, 7, //lewa
				0, 1, 5,   5, 4, 0,  //front
				3, 7, 6,   3, 6, 2,  //tyl
				4, 5, 6,   4, 6, 7  //gorna podstawa
				};
	//to chyba tyle

}
