//#include <ostream>
//#include <istream>
#include <iostream>
//#include <string>
#include <sstream>
#include <iomanip>

#if 0
std::string voidPtr2String( const void* ptr )
{
	int bitWidth = sizeof( void* ) * 8;

	std::ostringstream obuffer;
	obuffer << std::setw( bitWidth / 4 ) << std::hex << std::setfill( '0' ) << std::setiosflags( std::ios::uppercase );

	switch( bitWidth )
	{
	case 32:	// 32 bit
		obuffer << (unsigned long)( ptr );
		break;
	case 64:	// 64 bit
		obuffer << (unsigned long long)( ptr );
		break;
	default:
		break;
	}

	std::string address = obuffer.str();

	obuffer.str( "" );
	obuffer.clear();

	return address;
}

// 得考虑实际位宽以及传入地址的实际位宽。。。
void* string2VoidPtr( const std::string& address )
{
	if ( address.find( "0x" == 0 ) )
	{
		address = address.substr( 2, address.length() );
	}

	std::istringstream ibuffer;

	void* ptr = NULL;

	int bitWidth = address.length() * 4;
	//int bitWidth = sizeof( void* ) * 8;
	switch( bitWidth )
	{
	case 32:	// 32 bit
		{
			unsigned long tempptr = 0x0;
			ibuffer >> std::hex >> tempptr;
			ptr = (void*)tempptr;
			break;
		}
	case 64:	// 64 bit
		{
			unsigned long long tempptr = 0x0;
			ibuffer >> std::hex >> tempptr;
			ptr = (void*)tempptr;
			break;
		}
	default:
		break;
	}


	ibuffer.str( "" );
	ibuffer.clear();

	return ptr;
}
#else
std::string voidPtr2String( const void* ptr )
{
	std::ostringstream obuffer;
	obuffer<<ptr;

	return obuffer.str();
}

void* string2VoidPtr( const std::string& ptr )
{
	std::istringstream ibuffer(ptr);

	void* voidPtr;
	ibuffer >> voidPtr;

	return voidPtr;
}
#endif

int main( int argc, char** argv )
{
	//for( int i = 0; i < 300; i++ )
	{
		void* vptr = NULL;
		std::string svptr2 = "";

		int bitWidth = sizeof( void* ) * 8;

		if ( bitWidth == 32 )
		{
			vptr = (void*)0xAAAAAAAA;
			svptr2 = "55555555";
		}
		else if ( bitWidth == 64 )
		{
			vptr = (void*)0xAAAAAAAAAAAAAAAA;
			svptr2 = "5555555555555555";
		}

		std::string svptr = voidPtr2String( vptr );
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