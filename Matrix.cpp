#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> data;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), data(numRows, vector<int>(numCols, 0)) {}

    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        }
    }

    int getValue(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        }
        return -1; // Assuming -1 represents an invalid value
    }
};
