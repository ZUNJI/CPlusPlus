#include "Element.h"
#include "Visitor.h"

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
	Visitor* vis = new ConcreteVisitorA();
	Element* elm = new ConcreteElementA();
	elm->Accept( vis );

	Visitor* vis2 = new ConcreteVisitorB();
	Element* elm2 = new ConcreteElementB();
	elm2->Accept( vis2 );
	elm2->Accept( vis );

	return 0;
}