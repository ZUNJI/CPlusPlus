#include "Adapter2.h"

#include <iostream>

Target2::Target2()
{
}

Target2::~Target2()
{
}

void Target2::Request()
{
	std::cout << "Target2::Request" << std::endl;
}

Adaptee2::Adaptee2()
{
}

Adaptee2::~Adaptee2()
{
}

void Adaptee2::SpecificRequest()
{
	std::cout << "Adaptee2::SpecificRequest" << std::endl;
}

Adapter2::Adapter2()
{
}

Adapter2::~Adapter2()
{
}

void Adapter2::Request()
{
	this->SpecificRequest();
}