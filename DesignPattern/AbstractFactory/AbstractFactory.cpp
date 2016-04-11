#include "AbstractFactory.h"
#include "Product.h"

#include <iostream>

using namespace std;

AbstractFactory::AbstractFactory()
{
}

AbstractFactory::~AbstractFactory()
{
}

ConcreteFactory1::ConcreteFactory1()
{
}

ConcreteFactory1::~ConcreteFactory1()
{
	if ( _abstractProductA )
	{
		delete _abstractProductA;
		_abstractProductA = NULL;
	}

	if ( _abstractProductB )
	{
		delete _abstractProductB;
		_abstractProductB = NULL;
	}
}

AbstractProductA* ConcreteFactory1::CreateProductA()
{
	_abstractProductA = new ProductA1();
	return _abstractProductA;
}

AbstractProductB* ConcreteFactory1::CreateProductB()
{
	_abstractProductB = new ProductB1();
	return _abstractProductB;
}

ConcreteFactory2::ConcreteFactory2()
{
}

ConcreteFactory2::~ConcreteFactory2()
{
	if ( _abstractProductA )
	{
		delete _abstractProductA;
		_abstractProductA = NULL;
	}

	if ( _abstractProductB )
	{
		delete _abstractProductB;
		_abstractProductB = NULL;
	}
}

AbstractProductA* ConcreteFactory2::CreateProductA()
{
	_abstractProductA = new ProductA2();
	return _abstractProductA;
}

AbstractProductB* ConcreteFactory2::CreateProductB()
{
	_abstractProductB = new ProductB2();
	return _abstractProductB;
}