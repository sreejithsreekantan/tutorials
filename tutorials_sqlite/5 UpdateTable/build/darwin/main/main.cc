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

#define displayTable \
	sql =	"SELECT * FROM HOMELAND"; \
	res = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg); \
	if (res == SQLITE_OK) { \
		cout << "SQL Select successfully done.." << endl; \
	}\
	else {\
		cout << "SQL Select failded. PFB the error message:" << endl << zErrMsg << endl; \
		sqlite3_free(zErrMsg); \
	}	

int main(int argc, char *argv[])
{
	cout << "started...." << endl;

	sqlite3* db;
	char* zErrMsg = 0;
	char* sql = 0;
	// char* table_name = "HOMELAND";
	char* db_name="selecttable.db";
	const char* data = "Callback function called";

	int res = sqlite3_open(db_name, &db);

	switch(res) {
		case 0:
			cout << "Opened database successfully" << endl;
			break;
		default:
			cout << "Database opening failded. PFB the error message:" \
			<< endl << sqlite3_errmsg(db) << endl;
	}

	displayTable

	sql =	"UPDATE HOMELAND SET DESCRIPTION='BIG UNCLE OF ZERRY' WHERE ID=5";
	res = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if (res == SQLITE_OK) {
		cout << "SQL update successfully done.." << endl;
	}
	else {
		cout << "SQL update failded. PFB the error message:" \
			<< endl << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}	
	
	displayTable

	sqlite3_close(db);

	
	return 0;
}