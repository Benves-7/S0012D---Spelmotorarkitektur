#pragma once


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