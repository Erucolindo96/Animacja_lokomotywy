#include "Cylinder.h"



Cylinder::Cylinder():Actor()
{
}

Cylinder::Cylinder(const Cylinder & other):Actor(other)
{
}

Cylinder::Cylinder(const GLfloat r, const GLfloat h, const std::string texture_path, const GLuint verts_count):Actor()
{

	countAndSetVertsAndIndices(r, h, verts_count);
	setTextureFromFile(texture_path);
	bindVertexAndIndices();
}



std::unique_ptr<Actor> Cylinder::clone() const
{
	return std::unique_ptr<Actor>(new Cylinder(*this));
}

Cylinder::~Cylinder()
{
}

void Cylinder::countAndSetVertsAndIndices(const GLfloat r, const GLfloat h, GLuint sides)
{
	float deltaAngle = glm::two_pi<float>() / sides;

	for (GLuint i = 0; i < 2 * sides - 1; ++i) {
		indices_.emplace_back(2 * ((i + 1) / 2));
		indices_.emplace_back(i + 2);
		indices_.emplace_back(2 * ((i + 1) / 2) + 1);

		indices_.emplace_back(2 * ((i + 2) / 2));
		indices_.emplace_back(i + 3);
		indices_.emplace_back(2 * ((i + 1) / 2) + 1);
	}

	for (GLuint i = 1; i < sides - 1; ++i)
	{
		indices_.emplace_back(2 * sides + 2);
		indices_.emplace_back(2 * (i + 1) + 2 * sides + 2);
		indices_.emplace_back(2 * i + 2 * sides + 2);

		indices_.emplace_back(1 + 2 * sides + 2);
		indices_.emplace_back(2 * (i + 1) + 1 + 2 * sides + 2);
		indices_.emplace_back(2 * i + 1 + 2 * sides + 2);
	}

	for (GLuint i = 0; i <= sides; ++i) {
		float x = r * std::cos(deltaAngle * i);
		float y = r * std::sin(deltaAngle * i);

		verts_.emplace_back(glm::vec3(x, y, -h / 2), glm::normalize(glm::vec3(x, y, 0)), glm::vec2((float)i / 3 * sides, 0));
		verts_.emplace_back(glm::vec3(x, y, h / 2), glm::normalize(glm::vec3(x, y, 0)), glm::vec2((float)i / 3 * sides, 1));
	}

	for (GLuint i = 0; i < sides; ++i) {
		float x = r * std::cos(deltaAngle * i);
		float y = r * std::sin(deltaAngle * i);

		verts_.emplace_back(glm::vec3(x, y, -h / 2), glm::normalize(glm::vec3(0, 0, -1)), glm::vec2(x*0.5 / r + 0.5, y*0.5 / r + 0.5));
		verts_.emplace_back(glm::vec3(x, y, h / 2), glm::normalize(glm::vec3(0, 0, 1)), glm::vec2(x*0.5 / r + 0.5, y*0.5 / r + 0.5));
	}
}

