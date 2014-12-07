/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 
Read:
	http://www.cplusplus.com/doc/tutorial/typecasting/

Tips:
	static_cast can perform conversions between pointers to related classes, not only upcasts 
	(from pointer-to-derived to pointer-to-base), but also downcasts (from pointer-to-base to 
	pointer-to-derived). No checks are performed during runtime to guarantee that the object 
	being converted is in fact a full object of the destination type. Therefore, it is up to 
	the programmer to ensure that the conversion is safe. On the other side, it does not incur 
	the overhead of the type-safety checks of dynamic_cast.
*/
#include <iostream>
#include <utility/stdlib.h>
#include <cstdlib>		

#define MAX_BUFFER_SIZE 100

using namespace std;

class A { 
public: 
	operator int() {cout<<"operator int()"<<endl; return 101;}  // conversion operator
	A() {}
	A(int i) {cout<<"A(int i)"<<endl;}  // parameterized constructor
};

class B: public A { int i; };

int main(int argc, char *argv[])
{
	cout << "started...." << endl;
	
	try {
		A* a = new A();
		B* b = new B();

		B* db;

		db = static_cast<B*>(a);
		if (db==0) { cout << "A* to B* failed" << endl; } else { cout << "A* to B* " << endl; }

		db = static_cast<B*>(b);
		if (db==0) { cout << "B* to B* failed" << endl; } else { cout << "B* to B* " << endl; } 

		A* da;

		da = static_cast<B*>(a);
		if (db==0) { cout << "A* to A* failed" << endl; } else { cout << "A* to A* " << endl; }

		da = static_cast<B*>(b);
		if (db==0) { cout << "B* to A* failed" << endl; } else { cout << "B* to A* " << endl; }


		// Explicitly call a single-argument constructor or a conversion operator.
		int i = static_cast<int>(*a);

		// Convert to rvalue references.
		int& j = static_cast<int&>(i);
		cout << i << endl;

		// Convert any type to void, evaluating and discarding the value.
		static_cast<void>(j);
		// more example
		void* k = static_cast<void*>(&j);
		int* l = static_cast<int*>(k);
		cout << *l << endl;

	}catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}