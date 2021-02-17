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
	bool sendMessage(int index, Message message)
	{
		if (gameEntities[index])
		{
			gameEntities[index]->send(message);
		}
	}
	static Array<Ptr<GameEntity>> gameEntities;
};