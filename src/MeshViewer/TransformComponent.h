#pragma once
#include "BaseComponent.h"

using namespace Oryol;
class TransformComponent : public BaseComponent
{
	OryolClassDecl(TransformComponent)
public:
	TransformComponent(Ptr<GameEntity> entity, mat4 transform)
	{
		this->transform = transform;
		this->gameEntity = entity;
	}
	void init()
	{
		variable variable;
		variable.mat4 = new mat4(this->transform);
		this->gameEntity->registerVariable("transform", variable);
	}
private:
	mat4 transform;
	Ptr<GameEntity> gameEntity;

};