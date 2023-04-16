//
// Created by Ari on 2/21/2023.
//
#include "Table.h"
#include <string>
#include <vector>
#include <variant>
using std::vector, std::variant, std::string, std::get_if;

Table::Table(vector<variant<Column<int>, Column<string>, Column<bool>>> cols){
    this->cols = cols;
};

void Table::addBoolCol(Column<bool> col) {
    this->cols.push_back(col);
}

void Table::addTextCol(Column<std::string> col) {
    this->cols.push_back(col);
}

void Table::addIntCol(Column<int> col) {
    this->cols.push_back(col);
}

void Table::addRow(vector<variant<std::string, int, bool>> row) {
    for (int i=0; i< row.size(); i++) {
        variant<string, int, bool> val = row[i];
        variant<Column<int>, Column<string>, Column<bool>> col = cols[i];
        if (Column<int>* pval = get_if<Column<int>>(&col)) {
            if (int* nval = get_if<int>(&val)) {
                pval->addVal(*nval);
            }
        }
        if (Column<string>* pval = get_if<Column<string>>(&col)) {
            if (string* nval = get_if<string>(&val)) {
                pval->addVal(*nval);
            }
        }
        if (Column<bool>* pval = get_if<Column<bool>>(&col)) {
            if (bool* nval = get_if<bool>(&val)) {
                pval->addVal(*nval);
            }
        }
    }
}

vector<string> Table::getColNames() {
    vector<string> names;
    for (auto col : this->cols) {
        if (Column<int>* pval = get_if<Column<int>>(&col)) {
            names.push_back(pval->getName());
        }
        if (Column<string>* pval = get_if<Column<string>>(&col)) {
             names.push_back(pval->getName());
        }
        if (Column<bool>* pval = get_if<Column<bool>>(&col)) {
             names.push_back(pval->getName());
        }
    }
    return names;
}

vector<variant<string, int, bool>> Table::getRow(int rowIndex) {
    vector<variant<string, int, bool>> row;
    for (auto col : this->cols) {
        if (Column<int>* pval = get_if<Column<int>>(&col)) {
            row.push_back(pval->getVal(rowIndex));
        }
        if (Column<string>* pval = get_if<Column<string>>(&col)) {
            row.push_back(pval->getVal(rowIndex));
        }
        if (Column<bool>* pval = get_if<Column<bool>>(&col)) {
            row.push_back(pval->getVal(rowIndex));
        }
    }
    return row;
}

vector<vector<variant<string, int, bool>>> Table::whereQuery(string colName, variant<string, int, bool> val) {
    vector<int> rows;
    vector<string> names = getColNames();
    int index;
    for (int i=0; i< names.size(); i++) {
        string name = names[i];
        if (colName == name) {
            index = i;
        }
    }
    auto col = cols[index];
    if (Column<int>* pval = get_if<Column<int>>(&col)) {
        if (int* cval = get_if<int>(&val)) {
            for (int i=0; i<pval->getVals().size(); i++) {
                int value = pval->getVal(i);
                if (*cval==value) {
                    rows.push_back(i);
                }
            }
        }
    }
    if (Column<string>* pval = get_if<Column<string>>(&col)) {
        if (string* cval = get_if<string>(&val)) {
            for (int i=0; i<pval->getVals().size(); i++) {
                string value = pval->getVal(i);
                if (*cval==value) {
                    rows.push_back(i);
                }
            }
        }
    }
    if (Column<bool>* pval = get_if<Column<bool>>(&col)) {
        if (bool* cval = get_if<bool>(&val)) {
            for (int i=0; i<pval->getVals().size(); i++) {
                bool value = pval->getVal(i);
                if (*cval==value) {
                    rows.push_back(i);
                }
            }
        }
    }

    vector<vector<variant<string, int, bool>>> toRet;
    for (int i : rows) {
        vector<variant<string, int, bool>> row = getRow(i);
        toRet.push_back(row);
    }
    return toRet;

}

