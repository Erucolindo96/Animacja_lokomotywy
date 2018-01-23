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

Box::Box(const std::vector<Vertex>& base, GLfloat height, const std::string &texture_path): Actor()
{
	setTextureFromFile(texture_path);
	countAndSetVertsAndIndices(base, height);
	bindVertexAndIndices();

	//throw std::runtime_error("TODO");
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

void Box::countAndSetVertsAndIndices(const std::vector<Vertex> &base, const GLfloat height)
{
	auto box_verts = base;

	glm::vec3 normal = glm::triangleNormal(box_verts[0].position_, box_verts[1].position_, box_verts[2].position_);
	glm::vec3 up_base[4];
	//tworzymy wektor normalny o dlugosci heigth
	normal *= height;
	normal /= normal.length();

	for (int i = 0; i < 4; ++i)// 4 - to ilosc wierzcholkow podstawy
	{//przesuwamy podstawe o wektor normalny o dlugosci height
		up_base[i] = box_verts[i].position_ + normal;
	}
	
	for (int i = 0; i < 4; ++i)
	{
		Vertex v(box_verts[i]);
		v.position_ = up_base[i];
		box_verts.push_back(v);
	}

	//tworzymy na podstawie tej siatki 4 sciany - kazda z wlasnymi wierzcholkami


	//mamy wierzcholki - teraz kolejnosc renderingu
	indices_ = {0, 2 , 1,  0 ,3, 2, //podstawa dolna
				1, 2, 6,   6, 5, 1, // prawa
				0, 7, 3,   0, 4, 7, //lewa
				0, 1, 5,   5, 4, 0,  //front
				3, 7, 6,   3, 6, 2,  //tyl
				4, 5, 6,   4, 6, 7  //gorna podstawa
				};
	//to chyba tyle
	createAdditionalWalls(box_verts);
	throw std::runtime_error("TODO - zrobic obliczanie tekstur dla tego sposobu konstrukcji");

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

void Box::createAdditionalWalls(const std::vector<Vertex> &box_verts)
{
	//dolna podstawa
	for (int i = 0; i < 4; ++i)
	{
		verts_.push_back(box_verts[i]);
	}
	verts_[0].textCoord_ = { 1.0, 0.0 };
	verts_[1].textCoord_ = { 0.0, 0.0 };
	verts_[2].textCoord_ = { 1.0, 1.0 };
	verts_[3].textCoord_ = { 0.0, 1.0 };
	//przod
	verts_.push_back(box_verts[0]);
	verts_.push_back(box_verts[1]);
	verts_.push_back(box_verts[5]);
	verts_.push_back(box_verts[4]);
	verts_[4].textCoord_ = { 0.0, 0.0 };
	verts_[5].textCoord_ = { 1.0, 0.0 };
	verts_[6].textCoord_ = { 1.0, 1.0 };
	verts_[7].textCoord_ = { 1.0, 1.0 };
	//prawa
	verts_.push_back(box_verts[0]);
	verts_.push_back(box_verts[1]);
	verts_.push_back(box_verts[5]);
	verts_.push_back(box_verts[4]);
	verts_[4].textCoord_ = { 0.0, 0.0 };
	verts_[5].textCoord_ = { 1.0, 0.0 };
	verts_[6].textCoord_ = { 1.0, 1.0 };
	verts_[7].textCoord_ = { 1.0, 1.0 };


}


