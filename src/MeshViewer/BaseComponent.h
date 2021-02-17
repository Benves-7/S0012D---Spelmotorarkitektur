#pragma once

using namespace Oryol;

struct Message
{
	// HOLDER 
};

class BaseComponent : public RefCounted
{
public:
	virtual void init()
	{

	}
	virtual void update()
	{

	}
	virtual void shutdown()
	{

	}
	virtual void send(Message message)
	{

	}

private:

};