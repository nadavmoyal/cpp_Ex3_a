#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace zich
{
class Matrix {
private:
    int col;
    int row;
    vector<vector<double>> matrix;

public:
    Matrix(int c,int r,const vector<double> &m);
    ~Matrix();
    Matrix operator+(const vector<double> &m);
    Matrix operator+=(int num);
    Matrix operator++();
    Matrix operator--();


};
}
