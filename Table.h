//
// Created by Ari on 2/20/2023.
//

#ifndef DATABASE_TABLE_H
#define DATABASE_TABLE_H
#include "Column.h"
#include <vector>
#include <variant>
#include <string>
using std::vector, std::variant, std::string;
class Table {
private:
    vector<variant<Column<int>, Column<string>, Column<bool>>> cols;
    string name;
public:
    Table(vector<variant<Column<int>, Column<string>, Column<bool>>> cols);
    void addIntCol(Column<int> col);
    void addTextCol(Column<string> col);
    void addBoolCol(Column<bool> col);
    void addRow(vector<variant<string, int, bool>> row);
    vector<string> getColNames();
    vector<variant<string, int, bool>> getRow(int rowIndex);
    vector<vector<variant<string, int, bool>>> whereQuery(string colName, variant<string, int, bool> val);
};
#endif //DATABASE_TABLE_H
