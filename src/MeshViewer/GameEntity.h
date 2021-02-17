#pragma once
class GameEntity : public RefCounted
{
public:
	GameEntity();
	void init()
	{
		for (int i = 0; i < componentArray.Size(); i++)
		{
			GameEntity::componentArray[i]->init();
		}
	}
	void update()
	{
		for (int i = 0; i < componentArray.Size(); i++)
		{
			GameEntity::componentArray[i]->update();
		}
	}
	void shutdown()
	{
		for (int i = 0; i < componentArray.Size(); i++)
		{
			GameEntity::componentArray[i]->shutdown();
		}
	}
	void send(Message message)
	{

	}
	void addComponent(Ptr<BaseComponent> component)
	{
		componentArray.Add(component);
	}

private:
	static Array<Ptr<BaseComponent>> componentArray;
};