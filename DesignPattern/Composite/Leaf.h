#pragma once

#include "Component.h"

#include <iostream>

class Leaf : public Component
{
public:
	Leaf();
	~Leaf();

	virtual void Operation();

	virtual Component* GetChild( int index )
	{
		return NULL;
	};
};
