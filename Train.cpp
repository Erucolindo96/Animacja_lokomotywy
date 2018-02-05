#include "Train.h"




void Train::draw()
{
	kadlub_->draw();
	poklad_->draw();
	komin_->draw();
	for (auto &obicie : obicia_kadluba_)
	{
		obicie->draw();
	}
	dolne_obicie_kadluba->draw();
	for (auto &kolo : kolo_)
	{
		kolo->draw();
	}
}

std::unique_ptr<Actor> Train::clone() const
{
	return std::unique_ptr<Actor>(new Train(*this));
}

void Train::setDefaultTranslation(glm::vec3 translation)
{
	Actor::setDefaultTranslation(translation);
	//przesuniecie skladowych aktorow
	kadlub_->setDefaultTranslation(translation + DEFAULT_POS_KADLUB);
	poklad_->setDefaultTranslation(translation + DEFAULT_POS_POKLAD);
	komin_->setDefaultTranslation(translation + DEFAULT_POS_KOMIN);
	obicia_kadluba_[LEWE]->setDefaultTranslation(translation + DEFAULT_POS_OBICIE_LEWE);
	obicia_kadluba_[PRAWE]->setDefaultTranslation(translation + DEFAULT_POS_OBICIE_PRAWE);
	dolne_obicie_kadluba->setDefaultTranslation(translation + DEFAULT_POS_DOLNE_OBICIE);
	kolo_[LEWY_PRZOD]->setDefaultTranslation(translation + DEFAULT_POS_LP);
	kolo_[PRAWY_PRZOD]->setDefaultTranslation(translation + DEFAULT_POS_PP);
	kolo_[LEWY_SRODEK]->setDefaultTranslation(translation + DEFAULT_POS_LS);
	kolo_[PRAWY_SRODEK]->setDefaultTranslation(translation + DEFAULT_POS_PS);
	kolo_[LEWY_TYL]->setDefaultTranslation(translation + DEFAULT_POS_LT);
	kolo_[PRAWY_TYL]->setDefaultTranslation(translation + DEFAULT_POS_PT);
}

void Train::setTranslation(glm::vec3 translation)
{
	throw std::runtime_error("TODO");
	Actor::setTranslation(translation);
	//przesuniecie skladowych aktorow
	kadlub_->setTranslation(translation + DEFAULT_POS_KADLUB);
	poklad_->setTranslation(translation + DEFAULT_POS_POKLAD);
	komin_->setTranslation(translation + DEFAULT_POS_KOMIN);
	obicia_kadluba_[LEWE]->setTranslation(translation + DEFAULT_POS_OBICIE_LEWE);
	obicia_kadluba_[PRAWE]->setTranslation(translation + DEFAULT_POS_OBICIE_PRAWE);
	dolne_obicie_kadluba->setTranslation(translation + DEFAULT_POS_DOLNE_OBICIE);
	kolo_[LEWY_PRZOD]->setTranslation(translation + DEFAULT_POS_LP);
	kolo_[PRAWY_PRZOD]->setTranslation(translation + DEFAULT_POS_PP);
	kolo_[LEWY_SRODEK]->setTranslation(translation + DEFAULT_POS_LS);
	kolo_[PRAWY_SRODEK]->setTranslation(translation + DEFAULT_POS_PS);
	kolo_[LEWY_TYL]->setTranslation(translation + DEFAULT_POS_LT);
	kolo_[PRAWY_TYL]->setTranslation(translation + DEFAULT_POS_PT);

}

void Train::setShaderId(GLuint shader_id)
{
	Actor::setShaderId(shader_id);
	//propagacja ID do skladowych aktorow
	kadlub_->setShaderId(shader_id);
	poklad_->setShaderId(shader_id);
	komin_->setShaderId(shader_id);
	for (auto &obicie : obicia_kadluba_)
	{
		obicie->setShaderId(shader_id);
	}
	dolne_obicie_kadluba->setShaderId(shader_id);
	for (auto &kolo : kolo_)
	{
		kolo->setShaderId(shader_id);
	}
}

void Train::setDefaultRotation(glm::vec3 rotation_vec, GLfloat angle)
{
	throw std::runtime_error("TODO - nie uzywac tego, bo to robi konstruktor");
}

void Train::setRotation(glm::vec3 rotation_vec, GLfloat angle)
{
	throw std::runtime_error("TODO");
	
}


void Train::incrementRotationAngle()
{

	for (auto &kolo : kolo_)
	{
		kolo->incrementRotationAngle();
	}
}

void Train::decrementRotationAngle()
{
	for (auto &kolo : kolo_)
	{
		kolo->decrementRotationAngle();
	}
}

void Train::incrementRotationIncrementVelocity()
{
	for (auto &kolo : kolo_)
	{
		kolo->incrementRotationIncrementVelocity();
	}
}

void Train::decrementRotationIncrementVelocity()
{
	for (auto &kolo : kolo_)
	{
		kolo->decrementRotationIncrementVelocity();
	}
}

Train::Train() :Actor()
{
	kadlub_ = std::unique_ptr<Cylinder>(new Cylinder(3.0, 15, KADLUB_PATH, 10));
	kadlub_->setDefaultTranslation(DEFAULT_POS_KADLUB);
	
	poklad_ = std::unique_ptr<Box>(new Box(6, 9, 5, RUST2_PATH));
	poklad_->setDefaultTranslation(DEFAULT_POS_POKLAD);
	
	komin_ = std::unique_ptr<Cylinder>(new Cylinder(1, 3, RUST_PATH));
	komin_->setDefaultTranslation(DEFAULT_POS_KOMIN);
	komin_->setDefaultRotation({ 1.0, 0.0, 0.0 }, glm::radians(90.0));
	
	for (auto &ob : obicia_kadluba_)
	{
		ob = std::unique_ptr<Box>(new Box(0.5, 2, 14.9, RUST2_PATH));
	}
	obicia_kadluba_[LEWE]->setDefaultTranslation(DEFAULT_POS_OBICIE_LEWE);
	obicia_kadluba_[PRAWE]->setDefaultTranslation(DEFAULT_POS_OBICIE_PRAWE);
	dolne_obicie_kadluba = std::unique_ptr<Box>(new Box(4.5, 0.5, 14.9, RUST2_PATH));
	dolne_obicie_kadluba->setDefaultTranslation(DEFAULT_POS_DOLNE_OBICIE);
	
	const glm::vec3 WHEEL_ROT_VEC = { -1,0,0 };
	for (auto &kolo : kolo_)
	{
		kolo = std::unique_ptr<Cylinder>(new Cylinder(1.5, 0.5, WHEEL_PATH));
		kolo->setDefaultRotation({ 0.0, 1.0, 0.0 }, glm::radians(90.0));
		kolo->setRotation(WHEEL_ROT_VEC, 0);
	}
	kolo_[LEWY_PRZOD]->setDefaultTranslation(DEFAULT_POS_LP);
	kolo_[PRAWY_PRZOD]->setDefaultTranslation(DEFAULT_POS_PP);
	kolo_[LEWY_SRODEK]->setDefaultTranslation(DEFAULT_POS_LS);
	kolo_[PRAWY_SRODEK]->setDefaultTranslation(DEFAULT_POS_PS);
	kolo_[LEWY_TYL]->setDefaultTranslation(DEFAULT_POS_LT);
	kolo_[PRAWY_TYL]->setDefaultTranslation(DEFAULT_POS_PT);

}

Train::Train(const Train & other):Actor(other), kadlub_(other.kadlub_->clone()), poklad_(other.poklad_->clone())
, komin_(other.komin_->clone()), dolne_obicie_kadluba(other.dolne_obicie_kadluba->clone())
{
	for (int i=0; i< STRONY_KADLUBA; ++i)
	{
		obicia_kadluba_[i] = other.obicia_kadluba_[i]->clone();
	}
	for (int i = 0; i < ILOSC_KOL; ++i)
	{
		kolo_[i] = other.kolo_[i]->clone();
	}
}


Train::~Train()
{
}
