#include "Cylinder.h"



Cylinder::Cylinder():Actor()
{
}

Cylinder::Cylinder(const Cylinder & other):Actor(other)
{
}

Cylinder::Cylinder(const std::vector<Vertex>& sign_square_verts, const GLfloat height)
{
	const int SQUARE_VERTS = 4;
	if (sign_square_verts.size() != SQUARE_VERTS)
		throw std::logic_error("Cylinder::Zla ilosc wierzcholkow");
	//wylicz srodkowy wierzcholek podstawy
	glm::vec3 length = sign_square_verts[0].position_ - sign_square_verts[2].position_;
	glm::vec3 center_vert_pos = sign_square_verts[2].position_ + length / 2.0f;
	Vertex center_vert(center_vert_pos, sign_square_verts[2].color_, sign_square_verts[2].normal_, sign_square_verts[2].textCoord_);
	
	countAndSetVertsAndIndices(countCylinderBase(sign_square_verts, center_vert ), height);
	bindVertexAndIndices();
}


std::unique_ptr<Actor> Cylinder::clone() const
{
	return std::unique_ptr<Actor>(new Cylinder(*this));
}

Cylinder::~Cylinder()
{
}

void Cylinder::countAndSetVertsAndIndices(std::vector<Vertex>&& base, const GLfloat height)
{
	verts_ = std::move(base);
	glm::vec3 normal_to_base =glm::normalize( glm::triangleNormal(verts_[0].position_, verts_[4].position_, verts_[8].position_) );
	normal_to_base *= height;
	//utworz gorna podstawe na podstawie dolnej i wektora normalnego o dlugosci heigth
	int base_size = verts_.size();
	for (int i = 0; i < base_size; ++i)
	{
		const Vertex & vert_ref = verts_[i];
		glm::vec3 new_vert_pos = vert_ref.position_ + normal_to_base;
		verts_.push_back(Vertex(new_vert_pos, vert_ref.color_, vert_ref.normal_, vert_ref.textCoord_));
	}

	indices_ = {0,1,16,   1,2,16,   2,3,16,   3,4,16,//najpierw podstawa dolna
				4,5,16,   5,6,16,   6,7,16,    7,8,16,
				8,9,16,	  9,10,16,  10,11,16,  11,12,16,
				12,13,16, 13,14,16,  14,15,16,   15,0,16,
				//krawedzie boczne
				0,17,18,  0,18,1,   1,18,19,    1, 19, 2,
				2,19,20,  2,20,3,	3,20,21,	3,21,4,
				4,21,22,  4,22,5,	5,22,23,	5,23,6,
				6,23,24,  6,24,7,	7,24,25,	7,25,8,
				8,25,26,  8,26,9,	9,26,27,	9,27,10,
				10,27,28, 10,28,11,	11,28,29,	11,29,12,
				12,29,30, 12,30,13,	13,30,31,	13,31,14,
				14,31,32, 14,32,15, 15,32,17,	15,17,0,
				//podstawa gorna
				33,18,17,	33,19,18,	33,20,19,	33,21,20,
				33,22,21,	33,23,22,	33,24,23,	33,25,24,
				33,26,25,	33,27,26,	33,28,27,	33,29,28,
				33,30,29,	33,31,30,	33,32,31,	33,17,32
	};

}

std::vector<Vertex> Cylinder::countCylinderBase(const std::vector<Vertex>& sign_square_verts, const Vertex center_vertex)
{
	const int SQUARE_VERTS = 4;
	std::vector<Vertex> base;
	//stworz macierz obrotu wzdluz wektora normalnego
	glm::vec3 normal_vect = glm::triangleNormal(sign_square_verts[0].position_, sign_square_verts[1].position_, sign_square_verts[2].position_);
	glm::mat4 round_matrix;
	round_matrix = glm::rotate(round_matrix, glm::radians(22.5f), normal_vect);

	//dodaj zerowy wierzcholek kwadratu do podstawy
	Vertex first = Vertex(sign_square_verts[0]);
	base.push_back(first);
	//obracaj wierzcholek kwadratu i dodawaj utworzone wierzcholki do podstawy 
	glm::vec3 rounded_pos = sign_square_verts[0].position_;
	for (int i = 1; i < SQUARE_VERTS * 4 ; ++i) //od 1 bo juz zerowy mamy
	{
		const Vertex &square_vertex = sign_square_verts[i / 4];
		rounded_pos = glm::vec3( round_matrix * glm::vec4(rounded_pos, 1.0f) );
		base.push_back(Vertex(rounded_pos, square_vertex.color_, square_vertex.normal_, square_vertex.textCoord_) );
		
	}
	//dodaj na koniec srodkowy wierzcholek
	base.push_back(center_vertex);
	return base;
} 
