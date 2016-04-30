#include "Decorator.h"

#include <iostream>

#include <common.h>

using namespace std;

int main( int argc, char* argv[] )
{
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator( com );
	dec->Operation();

	checkAndDeletePoint( com );
	checkAndDeletePoint( dec );

	return 0;
}