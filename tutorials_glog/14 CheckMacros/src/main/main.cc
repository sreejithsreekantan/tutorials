/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

Tips:
	Execute following commands in terminal to view the difference:
	> make

struct S {
    S(Something* ptr) : ptr_(CHECK_NOTNULL(ptr)) {}
    Something* ptr_;
};
Note that you cannot use this macro as a C++ stream due to this feature. 
Please use CHECK_EQ described above to log a custom message before aborting 
the application. 
The CASE versions are case-insensitive. You can safely pass NULL pointers 
for this macro. They treat NULL and any non-NULL string as not equal. Two 
NULLs are equal. 

If you are comparing C strings (char *), a handy set of macros performs 
case sensitive as well as case insensitive comparisons - CHECK_STREQ, 
CHECK_STRNE, CHECK_STRCASEEQ, and CHECK_STRCASENE

The CHECK_DOUBLE_EQ macro checks the equality of two floating point values, 
accepting a small error margin. CHECK_NEAR accepts a third floating point 
argument, which specifies the acceptable error margin. 

*/
#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char const *argv[])
{

	cout << "started...." << endl;

	google::InitGoogleLogging(argv[0]);

	int i;

	while(i>-1) {
		cout << "\n\
		1. CHECK_NE(1, 2) \n\
		2. CHECK_NE(1, 1) \n\
		3. CHECK_EQ(string(\"abc\")[1], 'b') \n\
		4. CHECK_EQ(string(\"abc\")[0], 'b') \n\
		Select statement:";
		cin >> i;
        switch (i)
        {
        case 1:
            cout << "CHECK_NE(1, 2)" << endl;
            CHECK_NE(1, 2) << "Failed: CHECK_NE(1, 2)" << endl;
            break;
        case 2:
            cout << "CHECK_NE(1, 1)" << endl;
            CHECK_NE(1, 1) << "Failed: CHECK_NE(1, 1)" << endl;
            break;
        case 3:
            cout << "CHECK_EQ(string(\"abc\")[1], 'b')" << endl;
            // The compiler reports an error if one of the arguments is a pointer 
            // and the other is NULL. To work around this, simply static_cast NULL 
            // to the type of the desired pointer. 
            CHECK_EQ(string("abc")[1], 'b') << "Failed: CHECK_EQ(string(\"abc\")[1], 'b')" << endl;
            break;
        case 4:
            cout << "CHECK_EQ(string(\"abc\")[0], 'b')" << endl;
            CHECK_EQ(string("abc")[0], 'b') << "Failed: CHECK_EQ(string(\"abc\")[0], 'b')" << endl;
            break;
        default:
            cout << "Invalid choice..Try again.." << endl;
        }

	}

	cout << "end.." << endl;



	return 0;
}