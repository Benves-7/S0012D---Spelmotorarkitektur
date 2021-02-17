#pragma once
#include "Message.h"

class BaseComponent : public RefCounted
{
	OryolBaseClassDecl(BaseComponent);
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