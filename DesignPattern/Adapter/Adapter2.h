#ifndef _ADAPTER2_H_
#define _ADAPTER2_H_

class Target2
{
public:
	Target2();
	virtual ~Target2();
	virtual void Request();
};

class Adaptee2
{
public:
	Adaptee2();
	~Adaptee2();
	void SpecificRequest();
};

class Adapter2 :public Target2, private Adaptee2
{
public:
	Adapter2();
	~Adapter2();
	void Request();
};
#endif //~_ADAPTER2_H_