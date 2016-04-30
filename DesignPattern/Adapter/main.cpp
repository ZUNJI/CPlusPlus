#include "Adapter.h"
#include "Adapter2.h"

#include <common.h>

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
	Adaptee* ade = new Adaptee;
	Target* adt = new Adapter( ade );
	adt->Request();

	Target2* adt2 = new Adapter2();
	adt2->Request();

	checkAndDeletePoint( ade );
	checkAndDeletePoint( adt );
	checkAndDeletePoint( adt2 );

	return 0;
}