/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

Tips:
	Execute following commands in terminal to view the difference:
	> make
	> build/darwin/exe
	> make release
	> build/darwin/exe

*/
#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char const *argv[])
{

	cout << "started...." << endl;

	google::InitGoogleLogging(argv[0]);

	DLOG(INFO) << "This sentence is logged to DLOG(INFO)..\n";

	DLOG(ERROR) << "This sentence is logged to DLOG(ERROR)..\n";

	cout << "end.." << endl;

	return 0;
}