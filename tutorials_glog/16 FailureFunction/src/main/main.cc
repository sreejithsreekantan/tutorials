/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

Tips:
	Execute following commands in terminal to view the difference:
	> make


*/
#include <iostream>
#include <glog/logging.h>

using namespace std;

void my_failure_function() {
    cout << "[my_failure_function] : ERROR..." << endl;
    exit(1);
}

int main(int argc, char const *argv[])
{

	cout << "started...." << endl;

	google::InitGoogleLogging(argv[0]);
    google::InstallFailureFunction(&my_failure_function);

	CHECK(1==0) << "FAILED: CHECK(1==0) [ie. 1 is not equal to 0!]" << endl;

	cout << "end.." << endl;



	return 0;
}