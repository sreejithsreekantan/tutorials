/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <string>
#include <json/json.h>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "started...." << endl;
	string example = "{\"array\":[\"item1\", \"item2\"], \"not an array\":\"asdf\"}";
	Json::Value value;
	Json::Reader reader;

	bool parsed = reader.parse(example, value, false);
	cout << "PARSE: " << (parsed?"Success":"Failed") << endl;
	cout << value << endl;
	
	return 0;
}