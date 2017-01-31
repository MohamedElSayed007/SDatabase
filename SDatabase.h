/*
 * SDatabase.h
 *
 *      Author: Mohamed El Sayed
 *      email : m.elsayed4420@gmail.com
 *      lowlevelcode.blogspot.com
 */

#ifndef SDATABASE_H_
#define SDATABASE_H_
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>


using namespace std;

class SDatabase{
private:
	bool first_time = true;
	string reader(const string);
	void writer(string);
	string dbName="sdb_d.txt";
	bool check_db_init();

public:
	int entry_count=20;
	bool enable_duplication = true;
	bool exists(const string);
	string id;
	string *entries = new string[entry_count];
	void createDB(string);
	bool addNew();
	bool deleteById(const string);
	bool searchById(const string);
	int viewAll();
	void clear();
};


#endif /* SDATABASE_H_ */
