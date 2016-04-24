//he MIT License( MIT )
//
//
//opyright( c ) 2015 Jonathan Herp¨ºche
//
//
//ermission is hereby granted, free of charge, to any person obtaining a copy
//f this software and associated documentation files( the "Software" ), to deal
//n the Software without restriction, including without limitation the rights
//o use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//opies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE. 

// herpec - j / Singleton

#include <mutex>
#include <atomic>

class SpinLock final
{
public:
	// Constructors
	inline SpinLock( void )
		: atomicLock( false )
	{
		return;
	}

	SpinLock( SpinLock const & ) = default;

	SpinLock( SpinLock && ) = default;

	// Assignment Operators
	SpinLock &operator=( SpinLock const & ) = default;

	SpinLock &operator=( SpinLock && ) = default;

	// Destructor
	~SpinLock( void ) = default;

	// Methods
	inline void lock( void )
	{
		while ( atomicLock.exchange( true ) );
	}

	inline void unlock( void )
	{
		atomicLock = false;
	}

	inline bool isLocked( void ) const
	{
		return atomicLock;
	}

private:
	// Attributes
	std::atomic_bool atomicLock;
};

template <class Derived>
class Singleton
{
public:
	// Static Methods
	template <typename... Args>
	static inline Derived &GetInstance( Args &&...args )
	{
		return *GetInstancePointer( std::forward<Args>( args )... );
	}

	template <typename... Args>
	static inline Derived *GetInstancePointer( Args &&...args )
	{
		static Derived *instancePointer = CreateInstance( std::forward<Args>( args )... );
		return instancePointer;
	}

protected:
	using Access = Singleton<Derived>;
	// Constructors
	Singleton( void ) = default;
	Singleton( Singleton const & ) = default;
	Singleton( Singleton && ) = default;

	// Assignment Operators
	Singleton &operator=( Singleton const & ) = default;
	Singleton &operator=( Singleton && ) = default;

	// Destructor
	virtual ~Singleton( void ) = default;

private:
	// Static Attributes
	static Derived *instancePointer;
	static SpinLock lock;

	// Static Methods
	template <typename... Args>
	static inline Derived *CreateInstance( Args &&...args )
	{
		if ( Singleton::instancePointer == nullptr )
		{
			std::lock_guard<decltype( Singleton::lock )> lock( Singleton::lock );
			if ( Singleton::instancePointer == nullptr )
			{
				void *data = static_cast<void *>( GetData() );
				new ( data ) Derived( std::forward<Args>( args )... );
				Singleton::instancePointer = reinterpret_cast<Derived *>( data );
				std::atexit( &Singleton::DestroyInstance );
			}
		}
		return Singleton::instancePointer;
	}

	static inline void DestroyInstance( void )
	{
		reinterpret_cast<Derived *>( GetData() )->~Derived();
	}

	static inline unsigned char *GetData( void )
	{
		static unsigned char data[sizeof( Derived )];
		return data;
	}
};

template <class Derived>
Derived *Singleton<Derived>::instancePointer = nullptr;

template <class Derived>
SpinLock Singleton<Derived>::lock;
