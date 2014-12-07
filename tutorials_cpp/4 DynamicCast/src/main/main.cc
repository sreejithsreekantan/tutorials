/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

Read:
	http://www.cplusplus.com/doc/tutorial/typecasting/

Tips:
dynamic_cast can only be used with pointers and references to classes (or with void*). Its purpose 
is to ensure that the result of the type conversion points to a valid complete object of the destination 
pointer type.
This naturally includes pointer upcast (converting from pointer-to-derived to pointer-to-base), in 
the same way as allowed as an implicit conversion.
But dynamic_cast can also downcast (convert from pointer-to-base to pointer-to-derived) polymorphic 
classes (those with virtual members) if -and only if- the pointed object is a valid complete object 
of the target type.
*/

#include <iostream>
#include <utility/stdlib.h>
#include <cstdlib>		

#define MAX_BUFFER_SIZE 100

using namespace std;

// class A { };
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

		db = dynamic_cast<B*>(a);
		if (db==0) { cout << "A* to B* failed" << endl; } else { cout << "A* to B* " << endl; }

		db = dynamic_cast<B*>(b);
		if (db==0) { cout << "B* to B* failed" << endl; } else { cout << "B* to B* " << endl; } 

		A* da;

		da = dynamic_cast<B*>(a);
		if (db==0) { cout << "A* to A* failed" << endl; } else { cout << "A* to A* " << endl; }

		da = dynamic_cast<B*>(b);
		if (db==0) { cout << "B* to A* failed" << endl; } else { cout << "B* to A* " << endl; }

	}catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}