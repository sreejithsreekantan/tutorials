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

using namespace std;

int main(int argc, char *argv[])
{
	try {
		
		const int i = 7000;
		int* j = const_cast<int*>(&i);
		cout << "&i : " << &i << " j : " << j  << endl;		// adresses are same

		cout << "*j : " << *j << endl;

		*j = 9000; // NOTE: may cause error depending on the compiler
		
		cout << "&i : " << &i << " j : " << j  << endl;		// adresses are same

		cout << "*j : " << *j << endl; // 9000 in clang++
		cout << "i : " << i << endl;	// 7000 in clang++

		// int x = 10;
		// int* y = &x;
		// *y = 11;
		// cout << "&x : " << &x << " y : " << y  << endl;		// adresses are same
		// cout << "x : " << x << endl;	 
		// cout << "*y : " << *y << endl; 
		


	}catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}
/*
sample output:
&i : 0x7fff54b128bc j : 0x7fff54b128bc
*j : 7000
&i : 0x7fff54b128bc j : 0x7fff54b128bc
*j : 9000
i : 7000
&x : 0x7fff5cd3d8a0 y : 0x7fff5cd3d8a0
x : 11
*y : 11
*/