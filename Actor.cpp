#include "Actor.h"



Actor::Actor(): translation_(0,0,0), rotation_vec_(0,0, 1), rot_angle_(0) //defaultowe wartosci ktore nie zmieniaja po³o¿enia wierzcho³ków
{
	priority_[TRANSLATION] = FIRST;
	priority_[ROTATION] = SECOND;//jakiekolwiek priorytety
	initBuffers();
}

Actor::Actor(const Actor & other): verts_(other.verts_), indices_(other.indices_), shader_id_(other.shader_id_)
, translation_(other.translation_), rotation_vec_(other.rotation_vec_), rot_angle_(other.rot_angle_) 
{
	priority_[TRANSLATION] = other.priority_[TRANSLATION];
	priority_[ROTATION] = other.priority_[ROTATION];
	initBuffers();
	bindVertexAndIndices();//zakladamy ze kopiowane pola sa znane i dlatego to wolamy
}


void Actor::setTranslation(glm::vec3 translation, Priority p)
{
	translation_ = translation;
	if (findIndexOfPriority(p) != -1)
		throw std::logic_error("Actor::setTranslation - priorytet juz istnieje");
	priority_[TRANSLATION] = p;
}

glm::vec3 Actor::getTranslation() const
{
	return translation_;
}

void Actor::setRotation(glm::vec3 rotation_vec, GLfloat angle, Priority p)
{
	rotation_vec_ = rotation_vec;
	rot_angle_ = angle;
	if (findIndexOfPriority(p) != -1)
		throw std::logic_error("Actor::setTranslation - priorytet juz istnieje");
	priority_[ROTATION] = p;
}

glm::vec3 Actor::getRotationVect() const
{
	return rotation_vec_;
}

GLfloat Actor::getRotationAngle() const
{
	return rot_angle_;
}

Priority Actor::getPriotiry(char number_of_tranformation)
{
	if (number_of_tranformation >= TRANSFORMATION_CNT || number_of_tranformation < 0)
		throw std::out_of_range("Actor::get Priority - nie istnieje transformacja o takim priorytecie");
	return priority_[number_of_tranformation];
}


void Actor::draw() const
{
	//chyba juz gotowe ---  throw std::runtime_error("TODO - zrobic obliczanie macierzy przeksztalcenia - uzyj fcji countTransformationMatrix");
	//dolacza swoja macierz przeksztalcenia - aby przeksztalcic swoje wierzcholki
	glUseProgram(shader_id_);
	GLuint model_Uniform = glGetUniformLocation(shader_id_, "model");
	glUniformMatrix4fv(model_Uniform, 1, GL_FALSE, glm::value_ptr(model_matrix));
	
	glBindVertexArray(VAO_);
	//mozna tu dopisac uzycie shadera
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

void Actor::setShaderModelMatrix(GLuint model_id)
{
	model_id_ = model_id;
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

void Actor::countAndSetVertsAndIndices()
{
}

glm::mat4 Actor::countTransformationMatrix()
{
	glm::mat4 transformation;
	if (priority_[TRANSLATION] == FIRST)
	{
		transformation = glm::translate(transformation, translation_);
		transformation = glm::rotate(transformation, glm::radians(rot_angle_), rotation_vec_);
	}
	else if (priority_[ROTATION] == FIRST)
	{
		transformation = glm::rotate(transformation, glm::radians(rot_angle_), rotation_vec_);
		transformation = glm::translate(transformation, translation_);
	}
	else
	{
		throw std::runtime_error("Wartosc priorytetu inna niz dozwolona");
	}
	model_matrix = transformation;
	return transformation;
}

char Actor::findIndexOfPriority(Priority p)
{
	for (char i = 0; i < TRANSFORMATION_CNT; ++i)
	{
		if (priority_[i] == p)
			return i;
	}
	return -1;
}



Vertex::Vertex()
{

}

Vertex::Vertex(const Vertex & other): position_(other.position_), normal_(other.normal_), textCoord_(other.textCoord_), color_(other.color_)
{}
