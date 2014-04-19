/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		GLOG_logtostderr=1 build/darwin/exe 

*/
#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char const *argv[])
{

	

	google::InitGoogleLogging(argv[0]);

	int i=0;

	cout << "started.... (i="<<i<<")" << endl;

	while(i<20) {
		// cout << ".";
		LOG_EVERY_N(ERROR, 5) << "Executing this log statement " << i << "th time (google::COUNTER=" << google::COUNTER  << ").." << endl;
		LOG_EVERY_N(ERROR, 5) << "Executing this log statement " << i << "th time (google::COUNTER=" << google::COUNTER  << ").." << endl;
		i++;
	}

	

	cout << "end.." << endl;

	return 0;
}