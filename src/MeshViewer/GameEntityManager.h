#pragma once
#include "GameEntity.h"

class EntityManager
{
public:
	EntityManager();
	void init()
	{
		for (int i = 0; i < gameEntities.Size(); i++)
		{
			gameEntities[i]->init();
		}
	}
	void update()
	{
		for (int i = 0; i < gameEntities.Size(); i++)
		{
			gameEntities[i]->update();
		}
	}
	void shutdown()
	{
		for (int i = 0; i < gameEntities.Size(); i++)
		{
			gameEntities[i]->shutdown();
		}
	}
	static Array<Ptr<GameEntity>> gameEntities;
};