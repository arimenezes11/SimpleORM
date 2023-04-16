//
// Created by Ari on 2/26/2023.
//
#include "Database.h"
#include "Engine.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string confFile, dbFile;
    confFile="testconf.txt";
    dbFile="testdb.txt";

    Database db;
    Engine e = Engine(dbFile, confFile);
    e.loadData();
    db.init(e);
    cout << db << endl;
    vector<variant<string, int, bool>> row;
    row.push_back("Tintin");
    row.push_back(5);
    row.push_back(true);
    db.addRow(row);
    db.save();
    Engine e2 = Engine(dbFile, confFile);
    e2.loadData();
    Database db2;
    db2.init(e2);
    if (row != db2.getRow(4)) {
        cout << "failed getrow test" << endl;
    }

    if (row != db2.getRow(4)) {
        cout << "Failed save->reload test" << endl;
    }
    auto query = db2.whereQuery("Male", true);
}