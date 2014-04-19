/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

Tips:
	Execute following commands in terminal to view the difference:
	> make
    > GLOG_logtostderr=1 GLOG_v=1 build/darwin/exe
    > GLOG_logtostderr=1 GLOG_v=3 build/darwin/exe
    > GLOG_logtostderr=1 GLOG_v=6 build/darwin/exe
    > GLOG_logtostderr=1 GLOG_v=0 build/darwin/exe
	
	module wise
    > GLOG_logtostderr=1 GLOG_vmodule=main=2 build/darwin/exe


*/
#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char const *argv[])
{

	cout << "started...." << endl;

	google::InitGoogleLogging(argv[0]);

	int i;

    VLOG(1) << "I'm printed when you run the program with --v=1 or higher";
    VLOG(2) << "I'm printed when you run the program with --v=2 or higher";
    VLOG(3) << "I'm printed when you run the program with --v=3 or higher";
    VLOG(4) << "I'm printed when you run the program with --v=4 or higher";
    VLOG(5) << "I'm printed when you run the program with --v=5 or higher";


	cout << "end.." << endl;



	return 0;
}