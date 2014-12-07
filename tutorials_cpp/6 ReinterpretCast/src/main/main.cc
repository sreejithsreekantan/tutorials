/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 
Read:
	http://www.cplusplus.com/doc/tutorial/typecasting/

Tips:
	reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes. 
	The operation result is a simple binary copy of the value from one pointer to the other. All pointer 
	conversions are allowed: neither the content pointed nor the pointer type itself is checked.
	It can also cast pointers to or from integer types. The format in which this integer value represents a 
	pointer is platform-specific. The only guarantee is that a pointer cast to an integer type large enough 
	to fully contain it (such as intptr_t), is guaranteed to be able to be cast back to a valid pointer.
	The conversions that can be performed by reinterpret_cast but not by static_cast are low-level operations 
	based on reinterpreting the binary representations of the types, which on most cases results in code which 
	is system-specific, and thus non-portable. For example:

	class A {  };
	class B {  };
	A * a = new A;
	B * b = reinterpret_cast<B*>(a);

	This code compiles, although it does not make much sense, since now b points to an object of a totally unrelated 
	and likely incompatible class. Dereferencing b is unsafe.
*/

#include <iostream>
#include <utility/stdlib.h>
#include <cstdlib>		

#define MAX_BUFFER_SIZE 100

using namespace std;

class A { };

class B: public A {  };

int main(int argc, char *argv[])
{
	cout << "started...." << endl;
	
	try {
		
		A a;
		B* b = reinterpret_cast<B*>(&a);

	}catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}