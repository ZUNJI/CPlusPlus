#include "Component.h"
#include "Composite.h"
#include "Leaf.h"

#include <common.h>


#ifdef UseVisitor

std::string getTab( int numTab )
{
	std::string result;

	for ( int num = 1; num < numTab; num++ )
	{
		result += "\t";
	}

	return result;
}

std::string getTab2( int numTab )
{
	std::string result;

	for ( int num = 1; num < numTab; num++ )
	{
		if ( num == 1 )
		{
			result += "|---";
		}
		else
		{
			result += "\t";
		}
	}

	return result;
}

class CVisitor : public Visitor
{
public:
	CVisitor()
		: _numTab( 0 )
		, getTabCustom( &getTab )
	{

	}

	~CVisitor()
	{
	}

protected:
	void apply( Component* component )
	{
		_numTab++;

		std::cout << (*getTabCustom )( _numTab ) << component->getName() << std::endl;

		component->traverse( *this );

		_numTab--;
	}

public:
	typedef std::string( getTabFuc )( int );

	getTabFuc *getTabCustom;

private:
	int _numTab;
};

Visitor::Visitor()
{
}

Visitor::~Visitor()
{
}

#endif // UseVisitor

int main( int argc, char** argv )
{
	Composite* root = new Composite();
	Component* leaf1 = new Leaf();
	Component* leaf2 = new Leaf();
	Component* leaf3 = new Leaf();
	Composite* composite = new Composite();

	root->setName( "root" );
	leaf1->setName( "leaf1" );
	leaf2->setName( "leaf2" );
	leaf3->setName( "leaf3" );
	composite->setName( "composite" );

	root->Add( leaf1 );
	root->Add( leaf2 );
	root->Add( composite );

	composite->Add( leaf3 );

	root->Operation();

	CVisitor visitor;
	root->accept( visitor );

	visitor.getTabCustom = &getTab2;
	root->accept( visitor );

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
