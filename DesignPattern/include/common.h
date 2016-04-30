#ifndef _COMMON_H_
#define _COMMON_H_

#include <vcruntime.h>

template< class T >
void checkAndDeletePoint( T t )
{
	if( t )
	{
		delete t;
		t = NULL;
	}
}

#endif // _COMMON_H_