/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <utility/stdlib.h>
// #include <cstdlib>		

using namespace std;
using utility::itoa;
using utility::atoi;



int main(int argc, char *argv[])
{
	cout << "started...." << endl;
	// MyClass m;
	// YourClass y;
	// m=y;
	char c[sizeof(int)];
	int i = 99713256;
	itoa(i,c);

	// memcpy(c, &i, 4);
	cout << c << endl;
	int j;
	atoi(j,c);
	// memcpy(&j, c, 4);
	cout << j << endl;

	
	return 0;
}