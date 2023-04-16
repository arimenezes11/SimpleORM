//
// Created by Ari on 2/20/2023.
//
#include "Database.h"
#include "Engine.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string confFile, dbFile;
    cout << "Please provide database configuration file: " << endl;

    getline(cin, confFile);
    cout << "Please provide the database file to use" << endl;

    getline(cin, dbFile);
    Database db;
    Engine e = Engine(dbFile, confFile);
    e.loadData();
    db.init(e);
    cout << db << endl;

    return 0;
}
