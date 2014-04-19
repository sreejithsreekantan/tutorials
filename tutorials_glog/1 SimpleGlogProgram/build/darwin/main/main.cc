/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char const *argv[])
{

	cout << "started...." << endl;

	google::InitGoogleLogging(argv[0]);

	LOG(INFO) << "This sentence is logged to LOG(INFO)..\n";

	LOG(ERROR) << "This sentence is logged to LOG(ERROR)..\n";

	cout << "end.." << endl;

	return 0;
}