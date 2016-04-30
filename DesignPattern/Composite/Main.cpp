#include "Component.h"
#include "Composite.h"
#include "Leaf.h"

#include <common.h>

int main( int argc, char** argv )
{
	Composite* root = new Composite();
	Component* leaf1 = new Leaf();
	Component* leaf2 = new Leaf();
	Composite* composite = new Composite();

	root->Add( leaf1 );
	root->Add( leaf2 );
	root->Add( composite );

	root->Operation();

	root->Remove( leaf2 );

	//clean up
	delete root;

	return 0;
}