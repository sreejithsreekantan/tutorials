/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 
	2. Log to Directory
		// -- generates log files except for which destination is specified in GLOG_log_dir
		GLOG_log_dir=/sreejith/workspace/cpp/tutorials_glog/glog-logs  i=[iwef] build/darwin/exe 
		OR
		GLOG_log_dir=/sreejith/workspace/cpp/tutorials_glog/glog-logs build/darwin/exe 
		OR
		
		// -- generates log files only for which destination is specified in "i"
		i=[iwef] build/darwin/exe 
		OR
		build/darwin/exe 

*/
	
#include <iostream>
#include <glog/logging.h>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{

	cout << "started(" << argv[0] << ")...." << endl;

	char* i = getenv("i");
	if (!i)
	{
		i = new char;
		do
			{
				cout << "Enter i or w or e or f : ";
				cin >> *i; 
			} while (!i || (*i!='i' && *i!='w' && *i!='e' && *i!='f') );	
	}

	// set log dir in code
	// FLAGS_log_dir="/sreejith/workspace/cpp/tutorials_glog/glog-logs";

	google::InitGoogleLogging(argv[0]);
	// google::InitGoogleLogging("glogtutorial");
	
	switch(*i) {
		case 'i':
			google::SetLogDestination(google::INFO, "/sreejith/workspace/cpp/tutorials_glog/glog-logs/tmp/");
			break;
		case 'w':
			google::SetLogDestination(google::WARNING, "/sreejith/workspace/cpp/tutorials_glog/glog-logs/tmp/"); 
			break;
		case 'e':
			google::SetLogDestination(google::ERROR, "/sreejith/workspace/cpp/tutorials_glog/glog-logs/tmp/");
			break;
		case 'f':
			google::SetLogDestination(google::FATAL, "/sreejith/workspace/cpp/tutorials_glog/glog-logs/tmp/"); 
			break;
		default:
			cout << "Not supposed to be here!" << endl;
			exit(1);
	}
	

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