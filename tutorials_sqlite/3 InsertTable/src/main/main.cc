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

#define createTable() \
	res = sqlite3_exec(db, sql, callback, 0, &zErrMsg); \
	if (res == SQLITE_OK) { \
		cout << "SQL Table successfully created.." << endl; \
	} \
	else {	\
		cout << "SQL Table creation failded. PFB the error message:" << endl << sqlite3_errmsg(db) << endl; \
	}


int main(int argc, char *argv[])
{
	cout << "started...." << endl;

	sqlite3* db;
	char* zErrMsg = 0;
	char* sql = 0;
	// char* table_name = "HOMELAND";
	char* db_name="inserttable.db";

	int res = sqlite3_open(db_name, &db);

	switch(res) {
		case 0:
			cout << "Opened database successfully" << endl;
			break;
		default:
			cout << "Database opening failded. PFB the error message:" \
			<< endl << sqlite3_errmsg(db) << endl;
			// exit(1);
			// cout << "TRYING TO CREATE TABLE(" << table_name << \
			// 	") FOR NEXT EXECUTION : " << createTable(table_name) \
			// 	 << endl;
	}

	sql =	"CREATE TABLE HOMELAND ("\
					"ID INT PRIMARY KEY NOT NULL," \
					"NAME 			TEXT NOT NULL," \
					"DESCRIPTION	TEXT NOT NULL " \
					");";
	
	createTable();
	
	sql =	"INSERT INTO HOMELAND( ID, NAME, DESCRIPTION) "\
			"VALUES (1, 'PSUZEAN', 'FARMER OF HOMELAND');" \
			"INSERT INTO HOMELAND( ID, NAME, DESCRIPTION) "\
			"VALUES (2, 'MICHAEL', 'HOUSEWIFE IN HOMELAND');"\
			"INSERT INTO HOMELAND( ID, NAME, DESCRIPTION) "\
			"VALUES (3, 'FINNER', 'CHEMIST OF HOMELAND');" \
			"INSERT INTO HOMELAND( ID, NAME, DESCRIPTION) "\
			"VALUES (4, 'ZERRY', 'DAUGHTER OF FINNER');" \
			"INSERT INTO HOMELAND( ID, NAME, DESCRIPTION) "\
			"VALUES (5, 'PERRY', 'UNCLE OF ZERRY');" \
			;
	
	res = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if (res == SQLITE_OK) {
		cout << "SQL Insertion successfully done.." << endl;
	}
	else {
		cout << "SQL Insertion failded. PFB the error message:" \
			<< endl << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		// exit(1);
	}	
	

	sqlite3_close(db);

	
	return 0;
}


