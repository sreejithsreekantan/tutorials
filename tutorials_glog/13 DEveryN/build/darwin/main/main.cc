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

	int i;

	while(i>-1) {
		cout << "Enter value(log if value is greater than 10; exit if value less than 0):";
		cin >> i;

		DLOG_IF(INFO, i>10) << "This sentence is logged to LOG(INFO)..\n";

		DLOG_IF(ERROR, i>10) << "This sentence is logged to LOG(ERROR)..\n";	
	}

	

	cout << "end.." << endl;

	return 0;
}