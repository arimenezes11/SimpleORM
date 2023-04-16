//
// Created by Ari on 2/21/2023.
//

#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H
#include "Engine.h"
#include "Table.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <variant>
using std::ifstream;
using std::string;
using std::vector;
using std::variant;
using std::getline;


class Database {

private:
    Engine& engine;
    Table table;
public:
    Database();
    void init(Engine& e);
    void addRow(vector<variant<string, int, bool>> row);
    vector<variant<string, int, bool>> getRow(int rowIndex);
    void save();
    vector<vector<variant<string, int, bool>>> whereQuery (string colName, variant<string, int, bool> val);
    friend std::ostream& operator << (std::ostream& outs, Database& db);

};


#endif //DATABASE_DATABASE_H
