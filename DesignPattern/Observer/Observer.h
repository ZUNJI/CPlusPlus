#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "Subject.h"

namespace SLCore
{

class Observer : public osg::Referenced
{
public:
	Observer();

public:
	// Use subject as a parameter to receives information from a variety of subjects.
    virtual void update( Subject* subject ) = 0;

protected:

	virtual ~Observer();
};

}

class ConcreteObserverA : public SLCore::Observer
{
public:
	ConcreteObserverA();

protected:
	virtual ~ConcreteObserverA();

	void update( SLCore::Subject* subject );
};

class ConcreteObserverB : public SLCore::Observer
{
public:
	ConcreteObserverB();

protected:
	virtual ~ConcreteObserverB();

	void update( SLCore::Subject* subject );
};

#endif //~_OBSERVER_H_