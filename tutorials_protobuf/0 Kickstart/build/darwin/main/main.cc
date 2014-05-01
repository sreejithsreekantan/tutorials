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
#include <string>
#include <bitset>
#include <proto/kickstart.pb.h>

using namespace std;


int main(int argc, char const *argv[])
{

	cout << "started...." << endl;

	// bitset<8> b(0x80);
	// cout << b << endl;

	// b=(b>>7);
	// cout << b << endl;

	// Verify that the version of the library that we linked against is
	// compatible with the version of the headers we compiled against.
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	Kickstart k;
	k.set_i(6219371);
	string s;
	k.SerializeToString(&s);
	cout << s << endl;

	Kickstart k1;
	k1.ParseFromString(s);

	cout << k1.has_i() << endl;
	cout << k1.i() << endl;
	
	// Optional:  Delete all global objects allocated by libprotobuf.
	google::protobuf::ShutdownProtobufLibrary();


	cout << "end.." << endl;



	return 0;
}