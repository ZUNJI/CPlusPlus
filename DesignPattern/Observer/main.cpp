#include "Subject.h"
#include "Observer.h"
#include <iostream>
using namespace std;
int main( int argc, char* argv[] )
{
	osg::ref_ptr<ConcreteSubject> sub = new ConcreteSubject();
	osg::ref_ptr<SLCore::Observer> o1 = new ConcreteObserverA();
    osg::ref_ptr<SLCore::Observer> o2 = new ConcreteObserverB();
    sub->attach( o1.get() );
    sub->attach( o2.get() );
    sub->notify();

    return 0;
}