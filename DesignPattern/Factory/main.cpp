#include "Factory.h"
#include "Product.h"

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
	Factory* fac = new ConcreteFactory();
	Product* p = fac->CreateProduct();

	if ( p )
	{
		delete p;
		p = NULL;
	}

	if ( fac )
	{
		delete fac;
		fac = NULL;
	}

	return 0;
}