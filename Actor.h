#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <GLFW\glfw3.h>
#include <SOIL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm\gtx\normal.hpp>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>
#include "Texture.h"

enum Priority
{
	FIRST,
	SECOND,
	NONE
};

struct Vertex
{
	glm::vec3 position_;//nie wiem czy nie powinny byc we wsporzednych znormalizowanych
	glm::vec3 normal_;//jak wyzej
	glm::vec2 textCoord_;


	Vertex();
	Vertex(const Vertex &other);
	Vertex(Vertex &&other);
	Vertex& operator=(const Vertex &other);
	Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textCoord) : position_(position), normal_(normal), textCoord_(textCoord) {}
	


};

class Actor
{
public:

	Actor();
	Actor(const Actor &other);
	Actor& operator=(const Actor& other);

	static const char TRANSLATION = 0, ROTATION = 1;//numery przeksztalcen
	float round_delta = 0.005f;
	

	virtual void setTranslation(const glm::vec3 &translation);
	virtual void setDefaultTranslation(glm::vec3 translation);
	
	glm::vec3 getTranslation()const;
	glm::vec3 getDefaultTranslation()const;

	virtual void setRotation(const glm::vec3 &rotation_vec, GLfloat angle);
	virtual void setDefaultRotation(glm::vec3 rotation_vec, GLfloat angle);
	
	glm::vec3 getDefaultRotationVect()const;
	GLfloat getDefaultRotationAngle()const;


	glm::vec3 getRotationVect()const;
	GLfloat getRotationAngle()const;


	virtual void incrementRotationAngle();
	virtual void decrementRotationAngle();
	virtual void incrementRotationIncrementVelocity();
	virtual void decrementRotationIncrementVelocity();
	




	std::vector<GLuint> getIndices()const;
	std::vector<Vertex> getVertices()const;

	GLuint getShaderId()const;
	virtual void setShaderId(GLuint shader_id);

	void setTextureFromFile(std::string file_name);
	virtual void draw();
	virtual std::unique_ptr<Actor> clone()const = 0;
	virtual ~Actor();


protected:
	
	std::vector<Vertex> verts_;
	std::vector<GLuint> indices_;
	
	glm::vec3 default_translation_, translation_;
	glm::vec3 default_rotation_vec_, rotation_vec_;
	glm::mat4 default_model_matrix;

	GLfloat default_rot_angle_, rot_angle_;
	
	GLuint shader_id_, model_id_;
	GLuint VBO_, VAO_, EBO_;
	std::unique_ptr<Texture> texture_ptr_;

	void setVertices(const std::vector<Vertex> &verts);
	void setIndices(const std::vector<GLuint> &indices);

	/**
		Metoda twrozy bufory OpenGla
	*/
	void initBuffers();

	/**
	Metoda dolacza  do buforow OpenGla wartosci pol klasy
	Nalezy ja zawolac w konstruktorach klas pochodnych gdy zostana juz dodane wartosci pol klasy
	*/
	void bindVertexAndIndices();

	virtual void countAndSetVertsAndIndices();

	virtual void loadAndSetTexture(const std::string &path);
	
	/**
	Metoda oblicza macierz przekstalcenia
	*/
	virtual glm::mat4 countTransformationMatrix()const;
	
};

