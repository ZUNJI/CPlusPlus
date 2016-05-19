#include "Component.h"
#include "Composite.h"
#include "Leaf.h"

#include <common.h>

int main( int argc, char** argv )
{
	Composite* root = new Composite();
	Component* leaf1 = new Leaf();
	Component* leaf2 = new Leaf();
	Component* leaf3 = new Leaf();
	Composite* composite = new Composite();

	root->Add( leaf1 );
	root->Add( leaf2 );
	root->Add( composite );

	composite->Add( leaf3 );

	root->Operation();

	root->Remove( leaf1 );
	root->Remove( leaf2 );

	//clean up
	delete root;
	root = NULL;

	checkAndDeletePoint( leaf1 );
	checkAndDeletePoint( leaf2 );
	checkAndDeletePoint( composite );

	return 0;
}