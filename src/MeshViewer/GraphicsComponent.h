#pragma once

#include "BaseComponent.h"

class GraphicsComponent : public BaseComponent
{
	OryolClassDecl(GraphicsComponent)
public:
	GraphicsComponent(Ptr<GameEntity> entity, graphicsObject object)
	{
		this->gameEntity = entity;
		this->object = object;
		this->meshName = object.name;
	}
	void init()
	{
		variable spec; 
		spec.vec4 = &object.material.specular;
		this->gameEntity->registerVariable("specular", spec);

		variable specPow;
		specPow.f = &object.material.specPower;
		this->gameEntity->registerVariable("specPower", specPow);

		variable diff;
		diff.vec4 = &object.material.diffuse;
		this->gameEntity->registerVariable("diffuse", diff);

		variable index; 
		index.i = &object.index;
		this->gameEntity->registerVariable("meshIndex", index);
	}

	graphicsObject object;
	char* meshName;

private:
	Ptr<GameEntity> gameEntity;

};