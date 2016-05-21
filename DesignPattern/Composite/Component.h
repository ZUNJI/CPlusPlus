#pragma once

#include <vcruntime.h>
#include <iostream>
#include <string>

#define UseVisitor

#ifdef UseVisitor

class Component;

class Visitor
{
public:
	virtual ~Visitor();
	virtual void apply( Component* component ) = 0;

protected:
	Visitor();
};

#endif // UseVisitor

class Component
{
public:
	virtual ~Component();

	virtual Component* GetComponent();

	virtual void Operation() = 0;

#ifdef UseVisitor
	void accept( Visitor& visitor );

	virtual void traverse( Visitor& visitor );
#endif // UseVisitor

	void setName( const std::string& name );
	std::string getName();

protected:
	Component();

protected:
	std::string _name;
};
