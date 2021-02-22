#pragma once
#include "BaseComponent.h"

using namespace Oryol;
class TransformComponent : public BaseComponent
{
	OryolClassDecl(TransformComponent)
public:
	TransformComponent(Ptr<GameEntity> entity, vec3 position)
	{
		this->transform = translate(mat4(), position);
		this->position = position;
		this->gameEntity = entity;
	}
	void init()
	{
		variable transform;
		transform.mat4 = new mat4(this->transform);
		this->gameEntity->registerVariable("transform", transform);

		variable pos;
		pos.vec4 = new vec4(this->position.x, this->position.y, this->position.z, 1);
		this->gameEntity->registerVariable("position", pos);
	}
private:
	mat4 transform;
	vec3 position;
	Ptr<GameEntity> gameEntity;

};