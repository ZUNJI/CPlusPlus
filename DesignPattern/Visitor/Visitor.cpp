#include "Visitor.h"
#include "Element.h"

#include <iostream>

using namespace std;

Visitor::Visitor()
{
}

Visitor::~Visitor()
{
}

ConcreteVisitorA::ConcreteVisitorA()
{
}

ConcreteVisitorA::~ConcreteVisitorA()
{
}

void ConcreteVisitorA::VisitConcreteElementA( Element* elm )
{
	cout << "ConcreteVisitorA will visit ConcreteElementA..." << endl;
}

void ConcreteVisitorA::VisitConcreteElementB( Element* elm )
{
	cout << "ConcreteVisitorA will visit ConcreteElementB..." << endl;
}

void ConcreteVisitorA::VisitConcreteElement( ConcreteElementA* elmA )
{
	cout << "self: ConcreteVisitorA will visit ConcreteElementA..." << endl;
}

void ConcreteVisitorA::VisitConcreteElement( ConcreteElementB* elmB )
{
	cout << "self: ConcreteVisitorA will visit ConcreteElementB..." << endl;
}

ConcreteVisitorB::ConcreteVisitorB()
{
}

ConcreteVisitorB::~ConcreteVisitorB()
{
}

void ConcreteVisitorB::VisitConcreteElementA( Element* elm )
{
	cout << "ConcreteVisitorB will visit ConcreteElementA..." << endl;
}

void ConcreteVisitorB::VisitConcreteElementB( Element* elm )
{
	cout << "ConcreteVisitorB will visit ConcreteElementB..."<<endl;
}

void ConcreteVisitorB::VisitConcreteElement( ConcreteElementA* elmA )
{
	cout << "self: ConcreteVisitorB will visit ConcreteElementA..." << endl;
}

void ConcreteVisitorB::VisitConcreteElement( ConcreteElementB* elmB )
{
	cout << "self: ConcreteVisitorB will visit ConcreteElementB..." << endl;
}