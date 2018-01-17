#pragma once
#include "Actor.h"
#include "Cylinder.h"
#include "Box.h"
class Train :
	public Actor
{
protected:
	static const int ILOSC_KOL = 4;
	void countPositionOfObjects();
	std::unique_ptr<Cylinder> komin_, kadlub_, kolo[ILOSC_KOL];
	std::unique_ptr<Box> daszek_, poklad_, obicia_kadluba_[2];
	
public:
	virtual void draw();
	virtual std::unique_ptr<Actor> clone()const ;
	virtual void setTranslation(glm::vec3 translation);
	virtual void setTranslationPriority(Priority p);

	virtual void setRotation(glm::vec3 rotation_vec, GLfloat angle);
	virtual void setRotationPriority(Priority p);

	Train();
	Train(const Train &other);
	
	virtual ~Train();
};

