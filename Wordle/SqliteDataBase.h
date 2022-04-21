#pragma once
#include "sqlite3.h"
#include <stdio.h>
#include "io.h"
#include <string>
#include <vector>
#include <iostream>
#include <string>

#include "Helper.h"

class SqliteDataBase {
public:
	SqliteDataBase();
	~SqliteDataBase();
	void clear();
	const std::string getRandomWord();
	bool checkIfWordExist(const std::string* word);
private:
	sqlite3* db;

};
