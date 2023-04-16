//
// Created by Ari on 2/20/2023.
//

#ifndef DATABASE_COLUMN_H
#define DATABASE_COLUMN_H
#include <vector>
#include <optional>
#include <string>
#include <iostream>
using std::vector, std::string;

template <typename T>
class Column {
private:
    vector<T> values;
    string name;
public:
    Column(string name) {
        this->name = name;
    };
    Column(string name, vector<T> vals) {
        this->name = name;
        this->values = vals;
    }
    T getVal(int index) {
        return values[index];
    }
    void addVal(T newVal) {
        values.push_back(newVal);
    }
    void updateVal(int index, T newVal) {
        values[index] = newVal;
    }
    void setVals(vector<T> vals) {
        this->values = vals;
    }
    vector<T> getVals() {
        return values;
    }
    string getName() {
        return this->name;
    }

};


#endif //DATABASE_COLUMN_H
