/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 
	2. Log all errors to a directory under different file SUFFIXES
		GLOG_minloglevel=[0123] GLOG_log_dir=/sreejith/workspace/cpp/tutorials_glog/glog-logs build/darwin/exe 

Tips:
	Run GLOG_minloglevel=3 GLOG_log_dir=/sreejith/workspace/cpp/tutorials_glog/glog-logs build/darwin/exe 
	Open all the log files. It will have only FATAL-log-messages

*/
	
#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char const *argv[])
{

	cout << "started(" << argv[0] << ")...." << endl;

	google::InitGoogleLogging(argv[0]);
	// google::InitGoogleLogging("glogtutorial");
	
	// while(1) {
	LOG(INFO) << "This sentence is logged to LOG(INFO)..\n";
	LOG(WARNING) << "This sentence is logged to LOG(WARNING)..\n";
	LOG(ERROR) << "This sentence is logged to LOG(ERROR)..\n";
	// }	
	// logs a FATAL error in debug mode 
	// but avoids halting the program in production by automatically 
	// reducing the severity to ERROR.
	LOG(DFATAL) << "This sentence is logged to LOG(DFATAL)..\n";

	// Logging a FATAL message terminates the program 
	// (after the message is logged)
	LOG(FATAL) << "This sentence is logged to LOG(FATAL)..\n";

	cout << "end.." << endl;

	return 0;
}