#include "Element.h"
#include "Visitor.h"

#include <iostream>

using namespace std;

Element::Element()
{
}

Element::~Element()
{
}

void Element::Accept( Visitor* vis )
{
}

ConcreteElementA::ConcreteElementA()
{
}

ConcreteElementA::~ConcreteElementA()
{
}

void ConcreteElementA::Accept( Visitor* vis )
{
	cout << "visiting ConcreteElementA..." << endl;
	vis->VisitConcreteElementA( this );

	cout << "self: visiting ConcreteElementA..." << endl;
	vis->VisitConcreteElement( this );
}

ConcreteElementB::ConcreteElementB()
{
}

ConcreteElementB::~ConcreteElementB()
{
}

void ConcreteElementB::Accept( Visitor* vis )
{
	cout << "visiting ConcreteElementB..." << endl;
	vis->VisitConcreteElementB( this );

	cout << "self: visiting ConcreteElementB..." << endl;
	vis->VisitConcreteElement( this );
}