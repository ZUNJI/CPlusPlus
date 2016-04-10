/************************************************************************/
/* 1¡¢×¢ÒâÊÍ·ÅÄÚ´æ                                             */
/************************************************************************/


#ifndef _SUBJECT_H_
#define _SUBJECT_H_

//#include <osg/Referenced>
#include <osg/observer_ptr>
#include <osg/Referenced>

#include <list>

namespace SLCore
{

class Observer;

typedef osg::observer_ptr<Observer> ObserverPtr;
//typedef Observer* ObserverPtr;
typedef std::list<ObserverPtr> ObserverList;

class Subject : public osg::Referenced
{
public:
	Subject();

protected:
    virtual ~Subject();

public:
	virtual const char* className() const = 0;

    virtual void attach( Observer* observer );

    virtual void detach( Observer* observer );

	void setCustomData( osg::Referenced* data );

	osg::Referenced* getCustomData();

    virtual void notify();

private:
    ObserverList*						_observers;
	osg::observer_ptr<osg::Referenced>		_data;
};

}


class ConcreteSubject : public SLCore::Subject
{
public:
    ConcreteSubject();

protected:
	virtual ~ConcreteSubject();

public:
	virtual const char* className() const { return "ConcreteSubject"; }
};
#endif //~_SUBJECT_H_