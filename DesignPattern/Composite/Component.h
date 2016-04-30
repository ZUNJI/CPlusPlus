#pragma once

#include <vcruntime.h>

class Component
{
public:
	virtual ~Component();

	virtual Component* GetComponent()
	{
		return NULL;
	};

	virtual void Operation() = 0;

	virtual Component* GetChild( int index ) = 0;

protected:
	Component();
};
