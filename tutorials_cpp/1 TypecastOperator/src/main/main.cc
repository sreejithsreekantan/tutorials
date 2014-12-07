/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <utility/stdlib.h>
#include <cstdlib>		

#define MAX_BUFFER_SIZE 100

using namespace std;

class YourClass {
	char c_[MAX_BUFFER_SIZE];
public:
	YourClass() { memset(c_,0, sizeof(int) ); } // refresh c_ memory
	void c(char c[]) { memcpy(c_, c, strlen(c) ); }

	friend ostream& operator<<( ostream& out, const YourClass& y );
};

ostream& operator<<( ostream& out, const YourClass& y ) {
	out << "c[4] : " << y.c_ << endl;
	return out;
}


class MyClass {
	int i_;
public:
	void i(int i) { this->i_ = i; }
	int i() { return this->i_; }
	operator YourClass() {
		YourClass* y = new YourClass();
		char c[sizeof(int)];
		utility::itoa(i_,c);
		y->c(c);
		return *y;
		// return YourClass();
	}
};



int main(int argc, char *argv[])
{
	cout << "started...." << endl;
	MyClass m;
	m.i(198232234);
	YourClass y;
	y=m;
	
	cout << y << endl;

	
	return 0;
}