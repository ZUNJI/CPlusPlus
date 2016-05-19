#include "Composite.h"

#include <iostream>

Composite::Composite() :
	composite()
{
}

Composite::~Composite()
{
	composite.clear();
}

Component* Composite::GetComponent()
{
	return this;
}

void Composite::Operation()
{
	std::cout << "type: Composite name: " << _name << std::endl;

	for ( auto it = composite.begin(); it != composite.end(); it++ )
	{
		std::cout << "child: ";
		( *it )->Operation();
		//std::cout << std::endl;
	}
}

void Composite::Add( Component* component )
{
	composite.push_back( component );
}

void Composite::Remove( Component* component )
{
	for ( auto it = composite.begin(); it != composite.end(); it++ )
	{
		if ( *it == component )
		{
			composite.erase( it );
			break;
		}
	}
}

Component* Composite::GetChild( int index )
{
	std::vector<Component*>::iterator it = composite.begin() + index;
	return *it;
}