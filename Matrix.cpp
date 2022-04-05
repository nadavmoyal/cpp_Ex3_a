
#include "Martix.hpp"

using namespace zich;

    Matrix::Matrix(int c,int r,const vector<vector<double>> &m){ // need to check if its true to write like that.
        this->col=c;
        this->row=r;
        this->matrix=m 
    }

    Matrix::~Matrix(){}
    
    Matrix operator+(const vector<vector<double>> &m){
        if ( this->col!=m->col || this->row != m->row) {
             throw runtime_error("The matrices are not in the same size");
        } 
        vector<vector<double>> result;
        for(int i=0;i<(m->row);i++){    
            for(int j=0;j<(m->col);j++){
                result[i][j]=this->matrix[i][j]+this->m[i][j];
            }
        }
        return result;
    }
    
    
    Matrix operator+=(int num){
        for(int i=0;i<(m->row);i++){    
            for(int j=0;j<(m->col);j++){
              this->matrix[i][j]+=num;
            }
        }
        return this->matrix;
    }    
    
    Matrix operator++(){
        for(int i=0;i<(m->row);i++){    
            for(int j=0;j<(m->col);j++){
              this->matrix[i][j]+=1;
            }
        }
        return this->matrix;         
    }
    
    Matrix operator--(){
        for(int i=0;i<(m->row);i++){    
            for(int j=0;j<(m->col);j++){
              this->matrix[i][j]-=1;
            }
        }
        return this->matrix;
    }         
    
    Matrix operator-(const vector<double> &m){
        if ( this->col!=m->col || this->row != m->row) {
             throw runtime_error("The matrices are not in the same size");
        } 
        vector<vector<double>> result;
        for(int i=0;i<(m->row);i++){    
            for(int j=0;j<(m->col);j++){
                result[i][j]=this->matrix[i][j]-this->m[i][j];
            }
        }
        return result;
    }
    
    Matrix operator-=(int num){
        for(int i=0;i<(m->row);i++){    
            for(int j=0;j<(m->col);j++){
              this->matrix[i][j]-=num;
            }
        }
        return this->matrix;
    } 
    
    double Matrix::sumOfMatrix(const vector<vector<double>> &matrix){
        int sum=0;
        for(int i=0;i<(m->row);i++){    
            for(int j=0;j<(m->col);j++){
              sum+=this->matrix[i][j];
            }
        }
        return sum;
    }  
    
    Matrix operator<(const vector<vector<double>> &m){
        double sum_a=sumOfMatrix(this->matrix);
        double sum_b=sumOfMatrix(this->matrix);
        if (sum_a<sum_b){
            return true;
        }
        return false;
    }
    







