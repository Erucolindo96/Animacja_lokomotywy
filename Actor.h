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
	
	/**
	Metody s³u¿¹ce do translacji i obrotu aktora.
	Gdy zostanie wywo³ana metoda draw() tworz¹ macierz przeksztalcenia, zaleznie od danego priorytetu.
	*/
	virtual void setTranslation(const glm::vec3 &translation);
	virtual void setDefaultTranslation(glm::vec3 translation);
	//virtual void setTranslationPriority(Priority p);
	glm::vec3 getTranslation()const;
	glm::vec3 getDefaultTranslation()const;

	virtual void setRotation(const glm::vec3 &rotation_vec, GLfloat angle);
	virtual void setDefaultRotation(glm::vec3 rotation_vec, GLfloat angle);
	//virtual void setRotationPriority(Priority p);
	glm::vec3 getDefaultRotationVect()const;
	GLfloat getDefaultRotationAngle()const;


	glm::vec3 getRotationVect()const;
	GLfloat getRotationAngle()const;


	virtual void incrementRotationAngle();
	virtual void decrementRotationAngle();
	virtual void incrementRotationIncrementVelocity();
	virtual void decrementRotationIncrementVelocity();
	//Priority getPriotiry(char number_of_tranformation);




	std::vector<GLuint> getIndices()const;
	std::vector<Vertex> getVertices()const;

	GLuint getShaderId()const;
	virtual void setShaderId(GLuint shader_id);
	void setShaderModelMatrix(GLuint model_id); //nie uzywac tego

	void setTextureFromFile(std::string file_name);
	virtual void draw();
	virtual std::unique_ptr<Actor> clone()const = 0;
	virtual ~Actor();


protected:
	
	//static const char TRANSFORMATION_CNT = 2;
	std::vector<Vertex> verts_;
	std::vector<GLuint> indices_;
	
	glm::vec3 default_translation_, translation_;
	glm::vec3 default_rotation_vec_, rotation_vec_;
	glm::mat4 default_model_matrix;

	GLfloat default_rot_angle_, rot_angle_;
	//Priority priority_[TRANSFORMATION_CNT];//2 - ilosc przeksztalcen
	
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
		Metoda tworzy bufory OpenGla 
	*/
	
	void bindVertexAndIndices();
	/**
		Metoda dolacza  do buforow OpenGla wartosci pol klasy
		Nalezy ja zawolac w konstruktorach klas pochodnych gdy zostana juz dodane wartosci pol klasy
	*/
	virtual void countAndSetVertsAndIndices();

	virtual void loadAndSetTexture(const std::string &path);
	/**
	Metoda oblicza macierz przekstalcenia
	*/
	virtual glm::mat4 countDefaultTransformationMatrix()const;
	virtual glm::mat4 countTransformationMatrix()const;
	//char findIndexOfPriority(Priority p);

};

