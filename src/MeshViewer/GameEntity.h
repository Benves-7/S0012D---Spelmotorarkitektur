#pragma once

union variable
{
	StringAtom* string;
	int* i;
	float* f;
	vec4* vec4;
	mat4* mat4;
};

class GameEntity : public RefCounted
{
public:
	GameEntity()
	{

	}
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
		for (int i = 0; i < componentArray.Size(); i++)
		{
			GameEntity::componentArray[i]->send(message);
		}
	}
	void addComponent(Ptr<BaseComponent> component)
	{
		componentArray.Add(component);
	}

	// variables.
	// return the variable.
	variable get(StringAtom key)
	{
		return variables[key];
	}
	// update value
	void set(StringAtom key, variable value)
	{
		variables[key] = value;
	}
	// check if key exist else 
	void registerVariable(StringAtom key, variable value)
	{
		if (!variables.Contains(key))
		{
			variables.AddUnique(key, value);
		}
	}

private:
	static Array<Ptr<BaseComponent>> componentArray;
	Map<StringAtom, variable> variables;
};