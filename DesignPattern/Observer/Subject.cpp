#include "Subject.h"

#include <iostream>

#include "Observer.h"

using namespace SLCore;

Subject::Subject()
{
    _observers = new ObserverList;
}

Subject::~Subject()
{
    if ( _observers )
    {
		_observers->clear();
		delete _observers;
        _observers = NULL;
    }
}

void Subject::attach( Observer* observer )
{
    _observers->push_front( observer );
}

void Subject::detach( Observer* observer )
{
    if ( observer != NULL )
        _observers->remove( observer );
}

void Subject::notify()
{
	if ( !_data )
	{
		OSG_INFO << "Subject:" << className() << " has none data to notify, skip notify observers." << std::endl;
		return;
	}

    ObserverList::iterator ObserverListIter;
    ObserverListIter = _observers->begin();
    for ( ; ObserverListIter != _observers->end(); )
    {
		if ( (*ObserverListIter).get() )
		{
			( *ObserverListIter )->update( this );
			ObserverListIter++;
		}
		else
		{
			OSG_INFO << "Subject:" << className() << " find a wrong observer, remove it from observer list." << std::endl;
			ObserverListIter = _observers->erase( ObserverListIter );
		}
    }
}

void Subject::setCustomData( osg::Referenced* data )
{
	if ( !data )
	{
		OSG_INFO << "Subject:" << className() << " set data to null." << std::endl;
	}
	_data = data; 
}

osg::Referenced* Subject::getCustomData()
{
	return _data.get();
}

ConcreteSubject::ConcreteSubject()
{

}

ConcreteSubject::~ConcreteSubject()
{

}