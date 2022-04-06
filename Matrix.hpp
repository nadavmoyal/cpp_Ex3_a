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
    vector<double> matrix;

public:
    Matrix(const vector<double> &m,int r,int c);
    ~Matrix();
    Matrix operator+(Matrix const &m);
    Matrix& operator+=(Matrix const &m);
    Matrix& operator++();
    Matrix& operator++(const int num);
    Matrix& operator--();
    Matrix& operator--(const int num);
    Matrix&operator-=(Matrix const &m);
    Matrix operator-(Matrix const &m);
    double sumOfMatrix(Matrix const &m);
    bool operator<(Matrix const &m);
    bool operator>(Matrix const &m);
    bool operator<=(Matrix const &m);
    bool operator>=(Matrix const &m);
    bool operator==(Matrix const &m);
    bool operator!=(Matrix const &m);
    Matrix& operator*=(double num);
    Matrix operator*(Matrix const &m);
    friend ostream& operator<<(ostream &out, const Matrix &m);
    friend istream& operator>>(ostream &out, const Matrix &m);
    double MultResult(Matrix const &m,int col,int row);
    friend Matrix operator-(Matrix &m);
    friend Matrix operator+(Matrix &m);
    friend Matrix operator*(double num, Matrix &m);






};
}
