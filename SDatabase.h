/*
 * SDatabase.h
 *
 *  Created on: Jan 22, 2015
 *      Author: Mohamed El Sayed
 *      email : engmohamedelsayed007@gmail.com
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
string reader(const string);
void writer(string);
string dbName;

public:
bool enable_multi = false;
bool exists(const string);
string id, name, address;
void createDB(string);
bool addNew();
bool deleteById(const string);
bool searchById(const string);
int viewAll();
void clear();
};




#endif /* SDATABASE_H_ */
