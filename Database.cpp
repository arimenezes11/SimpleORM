//
// Created by Ari on 2/21/2023.
//
#include <string>
#include <vector>
#include "Database.h"
#include <variant>
#include <iostream>
#include <iomanip>

using namespace std;

Database::Database(): engine(* new Engine("", "")), table(* new Table({})) {};

void Database::init(Engine &e) {
        this->engine = e;
        vector<vector<string>> raw_data = e.getDataRef();
        string conf = e.getConf();
        ifstream configFile("../"+conf);
        vector<string> colNames;
        vector<string> types;
        int numCols;

        // load column config
        configFile >> numCols;
        for (int i=0; i < numCols; i++) {
            string colConf;
            configFile >> colConf;
            int splitter = colConf.find(':');
            colNames.push_back(colConf.substr(0, splitter));
            types.push_back(colConf.substr(splitter));
        }

        // Table configuration
        vector<variant<Column<int>, Column<string>, Column<bool>>> cols;
        Table newTable = Table(cols);
        for (int i=0; i < colNames.size(); i++) {
            vector<string> data = raw_data[i];
            string name = colNames[i];
            string typeStr = types[i];
            if (typeStr == ":bool") {
                vector<bool> newVec;
                for (string s : data) {
                    newVec.push_back(std::stoi(s));
                }
                newTable.addBoolCol(Column(name, newVec));
            }
            else if (typeStr == ":string") {
                newTable.addTextCol(Column(name, data));
            }
            else if (typeStr == ":int") {
                vector<int> newVec;
                for (string s : data) {
                    newVec.push_back(std::stoi(s));
                }
                newTable.addIntCol(Column(name, newVec));
            }
        }
        this->table = newTable;
    }

void Database::addRow(vector<variant<string, int, bool>> row) {
    table.addRow(row);
    vector<vector<string>> raw_data = engine.getDataRef();
    for (int i=0;i<raw_data.size();i++){
        vector<string> col = raw_data[i];
        variant<string, int, bool> val = row[i];
        if (int* pval = get_if<int>(&val)) {
            col.push_back(std::to_string(*pval));
        }
        if (string* pval = get_if<string>(&val)) {
            col.push_back(*pval);
        }
        if (bool* pval = get_if<bool>(&val)) {
            col.push_back(std::to_string(*pval));
        }
        raw_data[i] = col;
    }
    engine.save_data(raw_data);
}

void Database::save() {
    engine.save();
}

std::ostream &operator<<(ostream &outs, Database &db) {
    // print col headers
    vector<string> names = db.table.getColNames();
    for (string name : names) {
        outs << left << setw(20) << name;
    }
    outs << endl;
    vector<vector<string>> raw_data = db.engine.getDataRef();
    for (int i=0; i<raw_data[0].size();i++) {
        for (vector<string> col : raw_data) {
            outs << left << setw(20) << col[i];
        }
        outs << endl;
    }
    return outs;
}

vector<variant<string, int, bool>> Database::getRow(int rowIndex) {
    return table.getRow(rowIndex);
}

vector<vector<variant<string, int, bool>>> Database::whereQuery(string colName, variant<string, int, bool> val) {
    return table.whereQuery(colName, val);
}

