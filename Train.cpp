#include "Train.h"



void Train::draw()
{
	throw std::runtime_error("TODO");
}

std::unique_ptr<Actor> Train::clone() const
{
	throw std::runtime_error("TODO");
	return std::unique_ptr<Actor>();
}

void Train::setTranslation(glm::vec3 translation)
{
	Actor::setTranslation(translation);
	komin_->setTranslation(translation);
	poklad_->setTranslation(translation);
	for (auto &b : obicia_kadluba_)
	{
		b->setTranslation(translation);
	}
	komin_->setTranslation(translation);
	kadlub_->setTranslation(translation);
	for (auto &c : kolo)
	{
		c->setTranslation(translation);
	}
}

void Train::setTranslationPriority(Priority p)
{
	Actor::setTranslationPriority(p);
	komin_->setTranslationPriority(p);
	poklad_->setTranslationPriority(p);
	for (auto &b : obicia_kadluba_)
	{
		b->setTranslationPriority(p);
	}
	komin_->setTranslationPriority(p);
	kadlub_->setTranslationPriority(p);
	for (auto &c : kolo)
	{
		c->setTranslationPriority(p);
	}
}

void Train::setRotation(glm::vec3 rotation_vec, GLfloat angle)
{
	Actor::setRotation(rotation_vec, angle);
	komin_->setRotation(rotation_vec, angle);
	poklad_->setRotation(rotation_vec, angle);
	for (auto &b : obicia_kadluba_)
	{
		b->setRotation(rotation_vec, angle);
	}
	komin_->setRotation(rotation_vec, angle);
	kadlub_->setRotation(rotation_vec, angle);
	for (auto &c : kolo)
	{
		c->setRotation(rotation_vec, angle);
	}
}

void Train::setRotationPriority(Priority p)
{
}

Train::Train()
{
}

Train::Train(const Train & other):Actor(other)
{
	throw std::runtime_error("TODO");
}


Train::~Train()
{
}
