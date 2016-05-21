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

#ifdef UseVisitor
void Component::accept( Visitor& visitor )
{
	visitor.apply( this );
}

void Component::traverse( Visitor& visitor )
{

}

#endif // UseVisitor

void Component::setName( const std::string& name )
{
	_name = name;
}

std::string Component::getName()
{
	return _name;
}
