/*
Author: Sreejith Sreekantan

Tips:
	Execute following commands in terminal to view the difference:
	> scons
		g++ -o build/darwin/main/main.o -c build/darwin/main/main.cc
	> build/darwin/exe

	> scons --release
		g++ -o build/darwin/main/main.o -c -O3 -s -DNDEBUG build/darwin/main/main.cc
	> build/darwin/exe

*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

	cout << "started...." << endl;

	cout << "end.." << endl;

	return 0;
}