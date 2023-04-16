//
// Created by Ari on 2/20/2023.
//

#include "Engine.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>
#include <variant>
using std::ifstream;
using std::string;
using std::vector;
using std::variant;
using std::getline;
using std::ofstream;
using std::endl;
Engine::Engine(std::string db, std::string conf) {
        this->db = db;
        this->conf = conf;
}

void Engine::loadData() {
        ifstream dbFile("../" + db);
        ifstream configFile("../" + conf);

        int numCols;
        configFile >> numCols;


        // load in data as strings
        vector<vector<string>> data;
        while (dbFile) {
            vector<string> row;
            bool flag = false;
            for (int i=0; i<numCols; i++) {
                string val;
                dbFile >> val;
                if (val != "") {
                    flag = true;
                    row.push_back(val);
                }
            }
            if (flag) {
                data.push_back(row);
            }
        }
        vector<vector<string>> transformed;
        for (int i=0; i<numCols; i++) {
            vector<string> emptyCol;
            transformed.push_back(emptyCol);
        }
        for (vector<string> row : data) {
            for (int i=0; i<numCols; i++) {
                vector<string>& col = transformed[i];
                string val = row[i];
                col.push_back(val);
            }
        }
        // orm manipulates the rest
        this->raw_data = transformed;
}

vector<vector<string>> Engine::getDataRef() {
    return this->raw_data;
}
string Engine::getDB() {
    return this->db;
}
string Engine::getConf() {
    return this->conf;
}

void Engine::save() {
    ofstream file;
    file.open("../"+db);
    vector<vector<string>> transformed;
    for (int i=0; i<raw_data[0].size();i++) {
        vector<string> emptyRow;
        transformed.push_back(emptyRow);
    }

    for (int i=0; i<raw_data.size();i++) {
        vector<string> col = raw_data[i];
        for (int j=0; j<col.size();j++) {
            transformed[j].push_back(col[j]);
        }
    }
    for (vector<string> row : transformed) {
        for (string val : row) {
            file << val << endl;
        }
    }
}
void Engine::save_data(vector<vector<std::string>> data) {
    this->raw_data = data;
}
