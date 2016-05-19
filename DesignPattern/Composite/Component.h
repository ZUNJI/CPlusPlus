#pragma once

#include <vcruntime.h>
#include <iostream>
#include <string>

class Component
{
public:
	virtual ~Component();

	virtual Component* GetComponent();

	virtual void Operation() = 0;

	virtual Component* GetChild( int index ) = 0;

	void setName( const std::string& name );
	std::string getName();

protected:
	Component();

protected:
	std::string _name;
};
