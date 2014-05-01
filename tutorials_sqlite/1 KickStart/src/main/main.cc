/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <sqlite3.h>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "started...." << endl;

	sqlite3* db;
	char* zErrMsg = 0;

	int res = sqlite3_open("test.db", &db);

	switch(res) {
		case 0:
			cout << "Opened database successfully" << endl;
			break;
		default:
			cout << "Database opening failded. PFB the error message:" \
			<< endl << sqlite3_errmsg(db) << endl;
			exit(1);
	}

	sqlite3_close(db);

	
	return 0;
}