#include "Product.h"

#include <iostream>

using namespace std;

Product::Product()
{
}

Product::~Product()
{
}

void Product::ProducePart()
{
	cout << "ProducePart...." << endl;
}

ProductPart::ProductPart()
{

}

ProductPart::~ProductPart()
{

}

ProductPart* ProductPart::BuildPart()
{
	cout << "BuildPart...." << endl;
	return NULL;
}
