//#include <ostream>
//#include <istream>
#include <iostream>
//#include <string>
#include <sstream>
#include <iomanip>

std::string voidPtr2String( const void* ptr )
{
	std::ostringstream obuffer;
	obuffer << std::setw( sizeof( ptr ) * 2 ) << std::hex << std::setfill( '0' ) << std::setiosflags( std::ios::uppercase ) << (unsigned long long)( ptr );

	std::string address = obuffer.str();

	obuffer.str( "" );
	obuffer.clear();

	return address;
}

void* string2VoidPtr( const std::string& address )
{
	std::istringstream ibuffer( address );

	unsigned long long ptr = 0x0;
	ibuffer >> std::hex >> ptr;

	ibuffer.str( "" );
	ibuffer.clear();

	return (void*)( ptr );
}

int main( int argc, char** argv )
{
	for( int i = 0; i < 300; i++ )
	{
		void* vptr = (void*)0xAAAAAAAAAAAAAAAA;
		std::string svptr = voidPtr2String( vptr );
		//delete (int*)vptr;

		std::string svptr2 = "0x5555555555555555";
		void* vptr2 = string2VoidPtr( svptr2 );

		std::cout << svptr << std::endl;
		std::cout << vptr2 << std::endl;

		int* iptr = new int;
		*iptr = 123456;
		std::string siptr = voidPtr2String( (void*)iptr );
		std::cout << siptr << std::endl;

		void* viptr = string2VoidPtr( siptr );
		std::cout << viptr << std::endl;
		std::cout << *(int*)viptr << std::endl;

		delete iptr;
	}

	return 0;
}