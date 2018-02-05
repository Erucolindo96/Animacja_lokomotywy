#include "Actor.h"



Actor::Actor(): default_translation_(0,0,0), default_rotation_vec_(0,0, 1), default_rot_angle_(0), translation_(0,0,0), rotation_vec_(0,0,1), rot_angle_(0) //defaultowe wartosci ktore nie zmieniaja po³o¿enia wierzcho³ków
{
	
	initBuffers();
	
}

Actor::Actor(const Actor & other): verts_(other.verts_), indices_(other.indices_), shader_id_(other.shader_id_)
, default_translation_(other.default_translation_), default_rotation_vec_(other.default_rotation_vec_), default_rot_angle_(other.default_rot_angle_),
translation_(other.translation_), rotation_vec_(other.rotation_vec_), rot_angle_(other.rot_angle_)
{
	if (other.texture_ptr_.get() != nullptr)
	{
		texture_ptr_ = other.texture_ptr_->clone();
	}

	initBuffers();
	bindVertexAndIndices();//zakladamy ze kopiowane pola sa znane i dlatego to wolamy

}

Actor & Actor::operator=(const Actor & other)
{
	if (&other == this)
		return *this;
	verts_ = other.verts_;
	indices_ = other.indices_;
	default_translation_ = other.default_translation_;
	translation_ = other.translation_;
	default_rotation_vec_ = other.default_rotation_vec_;
	rotation_vec_ = other.rotation_vec_;



	default_rot_angle_ = other.default_rot_angle_;
	rot_angle_ = other.rot_angle_;

	shader_id_ = other.shader_id_;
	model_id_ = other.model_id_;
	if(other.texture_ptr_.get() != nullptr)
		texture_ptr_ =  std::unique_ptr<Texture>(new Texture(other.texture_ptr_->getTexturePath()));
	initBuffers();
	bindVertexAndIndices();//zakladamy ze kopiowane pola sa znane i dlatego to wolamy

}


void Actor::setTranslation(const glm::vec3 & translation)
{
	translation_ = translation;
}

void Actor::setDefaultTranslation(glm::vec3 translation)
{
	default_translation_ = translation;

}
glm::vec3 Actor::getTranslation() const
{
	return translation_;
}

glm::vec3 Actor::getDefaultTranslation() const
{
	return default_translation_;
}

void Actor::setRotation(const glm::vec3 & rotation_vec, GLfloat angle)
{
	rotation_vec_ = rotation_vec;
	rot_angle_ = angle;
}

void Actor::setDefaultRotation(glm::vec3 rotation_vec, GLfloat angle)
{
	default_rotation_vec_ = rotation_vec;
	default_rot_angle_ = angle;

}

glm::vec3 Actor::getDefaultRotationVect() const
{
	return default_rotation_vec_;
}

GLfloat Actor::getDefaultRotationAngle() const
{
	return default_rot_angle_;
}

glm::vec3 Actor::getRotationVect() const
{
	return rotation_vec_;
}

GLfloat Actor::getRotationAngle() const
{
	return rot_angle_;

}

void Actor::incrementRotationAngle()
{
	rot_angle_ += round_delta;
}

void Actor::decrementRotationAngle()
{
	rot_angle_ -= round_delta;
}
void Actor::incrementRotationIncrementVelocity()
{
	const float MAX_DELTA = 0.5, INC_VAL = 0.0001;
	if (round_delta >= MAX_DELTA)
		return;
	round_delta += INC_VAL;


}
void Actor::decrementRotationIncrementVelocity()
{
	const float MIN_DELTA = 0.001, DEC_VAL = 0.0001;
	if (round_delta <= MIN_DELTA)
		return;
	round_delta -= DEC_VAL;
}

void Actor::loadAndSetTexture(const std::string &path)
{
	texture_ptr_ = std::unique_ptr<Texture>(new Texture(path));
}


void Actor::setTextureFromFile(std::string file_name)
{
	texture_ptr_ = std::unique_ptr<Texture>(new Texture(file_name));
}

void Actor::draw()
{
	glUseProgram(shader_id_);
	//dolacza swoja macierz przeksztalcenia - aby przeksztalcic swoje wierzcholki
	glm::mat4 model_mat = countTransformationMatrix();
	GLuint model_Uniform = glGetUniformLocation(shader_id_, "model");
	glUniformMatrix4fv(model_Uniform, 1, GL_FALSE, glm::value_ptr(model_mat));
	
	glBindVertexArray(VAO_);
	glBindTexture(GL_TEXTURE_2D, texture_ptr_->getIdTexBuffer());

	glDrawElements(GL_TRIANGLES, (GLsizei)indices_.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
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
	if (verts_.size() > 0 && indices_.size() > 0) // po to aby tam, gdzie nie mamy siatki tylko kompozycje obiektow z siatkami nie wywalilo wyjatku
	{
		glBufferData(GL_ARRAY_BUFFER, verts_.size() * sizeof(Vertex), &verts_[0], GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(GLuint), &indices_[0], GL_STATIC_DRAW);
	}
	//miejsce w pamieci wspolrzednych
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	//normalnych
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal_));
	//tekstury
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textCoord_));

	glBindVertexArray(0);

}

void Actor::countAndSetVertsAndIndices()
{
}

glm::mat4 Actor::countTransformationMatrix() const
{
	glm::mat4 transformation(1.0);
	transformation = glm::translate(transformation, translation_);
	transformation = glm::translate(transformation, default_translation_);

	transformation = glm::rotate(transformation, rot_angle_, rotation_vec_);
	transformation = glm::rotate(transformation, default_rot_angle_, default_rotation_vec_);

	return transformation;
}


Vertex::Vertex()
{

}

Vertex::Vertex(const Vertex & other): position_(other.position_), normal_(other.normal_), textCoord_(other.textCoord_)
{}
Vertex::Vertex(Vertex &&other) : position_(std::move(other.position_)), normal_(std::move(other.normal_)), textCoord_(std::move(other.textCoord_))
{}

Vertex & Vertex::operator=(const Vertex & other)
{
	if (this == &other)
		return *this;
	position_ = other.position_;
	normal_ = other.normal_;
	textCoord_ = other.textCoord_;
	return *this;
}

	
