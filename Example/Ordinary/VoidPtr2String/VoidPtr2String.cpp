//#include <ostream>
//#include <istream>
#include <iostream>
//#include <string>
#include <sstream>

std::string voidPtr2String( const void* ptr )
{
	std::ostringstream obuffer;
	obuffer<<ptr;

	return obuffer.str();
}

void* string2VoidPtr( const std::string& ptr )
{
	void* voidPtr;
	std::istringstream ibuffer(ptr);
	ibuffer >> voidPtr;

	return voidPtr;
}

int main( int argc, char** argv )
{
	void* vptr = (void*)0xAAAAAAAAAAAAAAAA;
	std::string svptr = voidPtr2String( vptr );
	//delete (int*)vptr;

	std::string svptr2 = "0x5555555555555555";
	void* vptr2 = string2VoidPtr( svptr2 );

	std::cout << svptr << std::endl;
	std::cout << vptr2 << std::endl;

	int* iptr = new int;
	delete iptr;
	std::string siptr = voidPtr2String( (void*)iptr );
	std::cout << siptr << std::endl;
}