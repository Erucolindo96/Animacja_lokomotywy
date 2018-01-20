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

void Train::setTranslation(glm::vec3 translation)
{
	Actor::setTranslation(translation);
	//przesuniecie skladowych aktorow
	kadlub_->setTranslation(translation + DEFAULT_POS_KADLUB);
	poklad_->setTranslation(translation + DEFAULT_POS_POKLAD);
	komin_-> setTranslation(translation + DEFAULT_POS_KOMIN);
	obicia_kadluba_[LEWE]->setTranslation(translation + DEFAULT_POS_OBICIE_LEWE);
	obicia_kadluba_[PRAWE]->setTranslation(translation + DEFAULT_POS_OBICIE_PRAWE);
	dolne_obicie_kadluba->setTranslation(translation + DEFAULT_POS_DOLNE_OBICIE);
	kolo_[LEWY_PRZOD]->setTranslation(translation + DEFAULT_POS_LP);
	kolo_[PRAWY_PRZOD]->setTranslation(translation + DEFAULT_POS_PP);
	kolo_[LEWY_SRODEK]->setTranslation(translation + DEFAULT_POS_LS);
	kolo_[PRAWY_SRODEK]->setTranslation(translation + DEFAULT_POS_PS);
	kolo_[LEWY_TYL]->setTranslation(translation + DEFAULT_POS_LT);
	kolo_[PRAWY_TYL]->setTranslation(translation + DEFAULT_POS_PT);
	/*	for (auto &b : obicia_kadluba_)
	{
		b->setTranslation(translation);
	}
*/
	
/*	for (auto &c : kolo)
	{
		c->setTranslation(translation);
	}
*/
}

void Train::setTranslationPriority(Priority p)
{
	throw std::runtime_error("TODO");
	Actor::setTranslationPriority(p);
	komin_->setTranslationPriority(p);
	poklad_->setTranslationPriority(p);
	for (auto &b : obicia_kadluba_)
	{
		b->setTranslationPriority(p);
	}
	komin_->setTranslationPriority(p);
	kadlub_->setTranslationPriority(p);
	for (auto &c : kolo_)
	{
		c->setTranslationPriority(p);
	}
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

void Train::setRotation(glm::vec3 rotation_vec, GLfloat angle)
{
	throw std::runtime_error("TODO");
	Actor::setRotation(rotation_vec, angle);
	komin_->setRotation(rotation_vec, angle);
	poklad_->setRotation(rotation_vec, angle);
	for (auto &b : obicia_kadluba_)
	{
		b->setRotation(rotation_vec, angle);
	}
	komin_->setRotation(rotation_vec, angle);
	kadlub_->setRotation(rotation_vec, angle);
	for (auto &c : kolo_)
	{
		c->setRotation(rotation_vec, angle);
	}
}

void Train::setRotationPriority(Priority p)
{
	throw std::runtime_error("TODO");
}

Train::Train() :Actor()
{
	kadlub_ = std::unique_ptr<Cylinder>(new Cylinder(3.0, 15, METAL_PATH));
	kadlub_->setTranslation(DEFAULT_POS_KADLUB);
	
	poklad_ = std::unique_ptr<Box>(new Box(6, 9, 5, WOOD_PATH));
	poklad_->setTranslation(DEFAULT_POS_POKLAD);
	
	komin_ = std::unique_ptr<Cylinder>(new Cylinder(1.5, 3, WOOD_PATH));
	komin_->setTranslation(DEFAULT_POS_KOMIN);
	komin_->setRotation({ 1.0, 0.0, 0.0 }, glm::radians(90.0));
	
	for (auto &ob : obicia_kadluba_)
	{
		ob = std::unique_ptr<Box>(new Box(0.5, 2, 14.9, WOOD_PATH));
	}
	obicia_kadluba_[LEWE]->setTranslation(DEFAULT_POS_OBICIE_LEWE);
	obicia_kadluba_[PRAWE]->setTranslation(DEFAULT_POS_OBICIE_PRAWE);
	dolne_obicie_kadluba = std::unique_ptr<Box>(new Box(4.5, 0.5, 14.9, WOOD_PATH));
	dolne_obicie_kadluba->setTranslation(DEFAULT_POS_DOLNE_OBICIE);
	
	for (auto &kolo : kolo_)
	{
		kolo = std::unique_ptr<Cylinder>(new Cylinder(1.5, 0.5, METAL_PATH));
		kolo->setRotation({ 0.0, 1.0, 0.0 }, glm::radians(90.0));
	}
	kolo_[LEWY_PRZOD]->setTranslation(DEFAULT_POS_LP);
	kolo_[PRAWY_PRZOD]->setTranslation(DEFAULT_POS_PP);
	kolo_[LEWY_SRODEK]->setTranslation(DEFAULT_POS_LS);
	kolo_[PRAWY_SRODEK]->setTranslation(DEFAULT_POS_PS);
	kolo_[LEWY_TYL]->setTranslation(DEFAULT_POS_LT);
	kolo_[PRAWY_TYL]->setTranslation(DEFAULT_POS_PT);

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
