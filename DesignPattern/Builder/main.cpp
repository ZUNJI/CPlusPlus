#include "Builder.h"
#include "Product.h"
#include "Director.h"

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
	Builder* b = new ConcreteBuilder;
	b->GetProduct();

	Director* d = new Director( b );
	d->Construct();
	b->GetProduct();

	if ( b )
	{
		delete b;
		b = NULL;
	}

	if ( d )
	{
		delete d;
		d = NULL;
	}

	return 0;
}