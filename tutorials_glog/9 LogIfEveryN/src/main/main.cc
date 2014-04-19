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

	while(i<30) {
		cout << "[i = " << i << "] ";
		cout.flush();
		LOG_IF_EVERY_N(ERROR, i%2 , 5) << "Executing (LOG_IF_EVERY_N(ERROR, i%2 , 5) )" << "(google::COUNTER=" << google::COUNTER  << ")..";
		cout << endl;
		i++;
	}

	

	cout << "end.." << endl;

	return 0;
}