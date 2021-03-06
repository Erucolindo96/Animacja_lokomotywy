#pragma once
#include "Actor.h"
#include "Cylinder.h"
#include "Box.h"

#include <memory>
class Train :
	public Actor
{
protected:


	const std::string METAL_PATH = "..\\Animacja_lokomotywy\\textures\\metal2.jpg",
		KADLUB_PATH = "..\\Animacja_lokomotywy\\textures\\blacha.jpg",
		WOOD_PATH  = "..\\Animacja_lokomotywy\\textures\\metal3.jpg",
		//OBICIA_PATH = "..\\Animacja_lokomotywy\\textures\\metal.jpg",
		WHEEL_PATH = "..\\Animacja_lokomotywy\\textures\\kolo.png",
		RUST_PATH = "..\\Animacja_lokomotywy\\textures\\rdza.png",
		RUST2_PATH = "..\\Animacja_lokomotywy\\textures\\rdza2.jpg";
	
	
	static const int ILOSC_KOL = 6, STRONY_KADLUBA = 2;
	static const int LEWY_PRZOD = 0, PRAWY_PRZOD = 1, LEWY_SRODEK = 2, PRAWY_SRODEK = 3, LEWY_TYL = 4, PRAWY_TYL = 5, LEWE = 0, PRAWE = 1;
	std::unique_ptr<Actor>kadlub_, poklad_, komin_, obicia_kadluba_[STRONY_KADLUBA], dolne_obicie_kadluba,  kolo_[ILOSC_KOL], daszek_  ;
	const glm::vec3 DEFAULT_POS_KADLUB = { 0.0,0.0,0.0 }, DEFAULT_POS_POKLAD = { 0.0, 1.0, 10.0 }, DEFAULT_POS_KOMIN = { 0.0, 4.0, -5.0 },
		DEFAULT_POS_OBICIE_LEWE = { 2.5, -2.5, 0 }, DEFAULT_POS_OBICIE_PRAWE = { -2.5, -2.5, 0 }, DEFAULT_POS_DOLNE_OBICIE = { 0, -3.25, 0 },
		DEFAULT_POS_LP = { 3, -3, -5 }, DEFAULT_POS_PP = { -3, -3,-5 }, DEFAULT_POS_LS = { 3, -3, 2 },
		DEFAULT_POS_PS = { -3, -3, 2 }, DEFAULT_POS_LT = { 3, -3, 10 }, DEFAULT_POS_PT = { -3, -3, 10 };


public:
	virtual void draw();
	virtual std::unique_ptr<Actor> clone()const ;
	virtual void setDefaultTranslation(glm::vec3 translation);
	virtual void setTranslation(glm::vec3 translation);
	
	virtual void setShaderId(GLuint shader_id);
	virtual void setDefaultRotation(glm::vec3 rotation_vec, GLfloat angle);
	virtual void setRotation(glm::vec3 rotation_vec, GLfloat angle);
	

	virtual void incrementRotationAngle();
	virtual void decrementRotationAngle();
	virtual void incrementRotationIncrementVelocity();
	virtual void decrementRotationIncrementVelocity();
	Train();
	Train(const Train &other);
	
	virtual ~Train();
};

