/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <sqlite3.h>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	for (int i = 0; i < argc; ++i) {
		cout << azColName[i] << " = " << (argv[i]?argv[i]:"NULL") << endl;
	}
	cout << endl;
	return 0;
}

int main(int argc, char *argv[])
{
	cout << "started...." << endl;

	sqlite3* db;
	char* zErrMsg = 0;

	int res = sqlite3_open("createtable.db", &db);

	switch(res) {
		case 0:
			cout << "Opened database successfully" << endl;
			break;
		default:
			cout << "Database opening failded. PFB the error message:" \
			<< endl << sqlite3_errmsg(db) << endl;
			exit(1);
	}

	char* sql =	"CREATE TABLE HOMELAND("\
					"ID INT PRIMARY KEY NOT NULL," \
					"NAME 			TEXT NOT NULL," \
					"DESCRIPTION	TEXT NOT NULL " \
					");";
	
	res = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	switch(res) {
		case 0:
			cout << "SQL successfully executed.." << endl;
			break;
		default:
			cout << "SQL execution failded. PFB the error message:" \
			<< endl << sqlite3_errmsg(db) << endl;
			exit(1);
	}

	sqlite3_close(db);

	
	return 0;
}