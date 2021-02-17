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
		spec.f = &object.material.specPower;
		this->gameEntity->registerVariable("specular", spec);

		variable diff;
		diff.vec4 = &object.material.diffuse;
		this->gameEntity->registerVariable("diffuse", diff);

		variable meshIndex; 
		meshIndex.i = &object.index;
		this->gameEntity->registerVariable("meshIndex", meshIndex);
	}

	graphicsObject object;
	char* meshName;

private:
	Ptr<GameEntity> gameEntity;

};