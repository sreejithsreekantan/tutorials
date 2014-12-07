/*
Author: Sreejith Sreekantan

Usage:
    1. Normal execution
        build/darwin/exe

Tips:
    explicit keyword can only be used inside class definitions
    'explicit' can only be applied to a constructor or conversion function

*/
#include <iostream>
#include <utility/stdlib.h>
#include <cstdlib>

#define MAX_BUFFER_SIZE 100

using namespace std;

#include <iostream>
using namespace std;



class A
{
public:
	A(const int& a) { } // --------------------------------------------------(1)
};

class B
{
public:
    explicit B(const int& a) { } // -----------------------------------------(2)
};

void fn(const A a) { }					// NOTE: A& ie. reference wont invoke implicit conversion
void e_fn(const B b) { }

int main(int argc, char *argv[])
{
    cout << "started...." << endl;
    
    int i = 101;
    float f = 202.202;

    try
    {
        fn(i);	// ----------------------------------------------------invokes (1)
        fn(f);	// ----------------------------------------------------invokes (1)

        // e_fn(i); // ------------------------------------causes error
        		 // due to 'explicit' keyword implicit conversions are disallowed
        // e_fn(f); // ------------------------------------causes error 
        		 // due to 'explicit' keyword implicit conversions are disallowed
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
