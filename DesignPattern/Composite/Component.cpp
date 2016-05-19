#include "Component.h"

Component::Component()
{
}

Component::~Component()
{
}

Component* Component::GetComponent()
{
	return NULL;
}

void Component::setName( const std::string& name )
{
	_name = name;
}

std::string Component::getName()
{
	return _name;
}
