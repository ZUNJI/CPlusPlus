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

	for ( std::vector<Component*>::iterator it = composite.begin(); it != composite.end(); it++ )
	{
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
	for ( std::vector<Component*>::iterator it = composite.begin(); it != composite.end(); it++ )
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

void Composite::traverse( Visitor& visitor )
{
	for ( std::vector<Component*>::iterator it = composite.begin(); it != composite.end(); it++ )
	{
		(*it)->accept( visitor );
	}
}
