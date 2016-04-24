#include "Prototype.h"

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
	Prototype* p = new ConcretePrototype();
	Prototype* p1 = p->Clone();

	//cout << "address p:  " << p << endl;
	//cout << "address p1: " << p1 << endl;

	if ( p )
	{
		delete p;
		p = NULL;
	}
	if ( p1 )
	{
		delete p1;
		p1 = NULL;
	}

	return 0;
}