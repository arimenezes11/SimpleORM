//
// Created by Ari on 2/20/2023.
//

#ifndef DATABASE_ENGINE_H
#define DATABASE_ENGINE_H
#include <iostream>
#include <vector>
using std::string, std::vector;
class Engine {
private:
    string db;
    string conf;
    vector<vector<string>> raw_data;
public:
    Engine(string db, string conf);
    void loadData();
    vector<vector<string>> getDataRef();
    string getDB();
    string getConf();
    void save();
    void save_data(vector<vector<string>> data);
};


#endif //DATABASE_ENGINE_H
