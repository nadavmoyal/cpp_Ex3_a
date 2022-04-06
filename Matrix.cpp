#include "Matrix.hpp"

namespace zich {

    Matrix::Matrix(const vector<double> &m,int r,int c){ // need to check if its true to write like that.
        this->col=c;
        this->row=r;
        this->matrix=m;
    }
    
    Matrix::~Matrix(){

    }
    
    Matrix Matrix::operator+(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        int length= m.col*m.row; 
        vector <double> result((unsigned int)(length), 0.0);
        for(int i=0;i<(m.row);i++){    
            for(int j=0;j<(m.col);j++){
                result[(unsigned int)(col*i+j)]=m.matrix[(unsigned int)(col*i+j)]+this->matrix[(unsigned int)(col*i+j)];
            }
        }
        Matrix res(result,this->row, m.col);

        return res;
    } 

    Matrix &Matrix::operator++(){
        for(int i=0;i<(this->row);i++){    
            for(int j=0;j<(this->col);j++){
                this->matrix[(unsigned int)(col*i+j)]+=1;
            }
        }
        return *this;
    }
    Matrix &Matrix::operator++(const int num){
        Matrix result= Matrix(this->matrix,this->row,this->col);
        for(int i=0;i<(this->row);i++){    
            for(int j=0;j<(this->col);j++){
               result.matrix[(unsigned int)(col*i+j)]+=1;
            }
        }
        return *this;
    }
    
    Matrix &Matrix::operator+=(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        for(int i=0;i<(m.row);i++){    
            for(int j=0;j<(m.col);j++){
                this->matrix[(unsigned int)(col*i+j)]+=m.matrix[(unsigned int)(col*i+j)];
            }
        }
        return *this;
    } 

    Matrix &Matrix::operator--(){
        for(int i=0;i<(this->row);i++){    
            for(int j=0;j<(this->col);j++){
                this->matrix[(unsigned int)(col*i+j)]-=1;
            }
        }
        return *this;
    }
    
    Matrix &Matrix::operator--(const int num){
        Matrix result= Matrix(this->matrix,this->row,this->col);
        for(int i=0;i<(this->row);i++){    
            for(int j=0;j<(this->col);j++){
               result.matrix[(unsigned int)(col*i+j)]-=1;
            }
        }
        return *this;
    }
    Matrix &Matrix::operator-=(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        for(int i=0;i<(m.row);i++){    
            for(int j=0;j<(m.col);j++){
                this->matrix[(unsigned int)(col*i+j)]-=m.matrix[(unsigned int)(col*i+j)];
            }
        }
        return *this;
    } 

     Matrix Matrix::operator-(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        int length= m.col*m.row; 
        vector <double> result((unsigned int)(length), 0.0);
        for(int i=0;i<(m.row);i++){    
            for(int j=0;j<(m.col);j++){
                result[(unsigned int)(col*i+j)]=this->matrix[(unsigned int)(col*i+j)]-m.matrix[(unsigned int)(col*i+j)];
            }
        }
        Matrix res(result,this->row, m.col);

        return res;
    } 
    
    double Matrix::sumOfMatrix(Matrix const &m){
        double sum=0;
        for(int i=0;i<(m.row);i++){    
            for(int j=0;j<(m.col);j++){
              sum+=m.matrix[(unsigned int)(col*i+j)];
            }
        }
        return sum;
    }  
    bool Matrix::operator<(Matrix const &m){
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        if (sum_a<sum_b){
            return true;
        }
        return false;
    }
    bool Matrix::operator>(Matrix const &m){
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        if (sum_a>sum_b){
            return true;
        }
        return false;
    }
    bool Matrix::operator<=(Matrix const &m){
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        if (sum_a<=sum_b){
            return true;
        }
        return false;
    }
    bool Matrix::operator>=(Matrix const &m){
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        if (sum_a>=sum_b){
            return true;
        }
        return false;
    }
    bool Matrix::operator==(Matrix const &m){
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        if (sum_a==sum_b){
            return true;
        }
        return false;
    }
    bool Matrix::operator!=(Matrix const &m){
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        if (sum_a!=sum_b){
            return true;
        }
        return false;
    }

     Matrix &Matrix::operator*=(double num){
        for(int i=0;i<(this->row);i++){    
            for(int j=0;j<(this->col);j++){
                this->matrix[(unsigned int)(col*i+j)]*=num;
            }
        }
        return *this;
    }

    Matrix Matrix::operator*(Matrix const &m){
        if( this->col!=m.row && this->row != m.col) {
             throw runtime_error("The matrices are not in the legal size for mult");
        }
        int length= m.col*this->row; 
        vector <double> result((unsigned int) (length), 0.0);
        return *this;
        // int i=0,j=0;
        // double temp=0;
        // while(i<this->col){
        //     while(j<m.row){

        //         // temp +=this->matrix[(int)(i*col+j)]*m.matrix[(int)(col*i+j)]
        //         // result[(int)(col*i+j)]=
        //     }
        // }
        
        // for(int i=0;i<(m.row);i++){    
        //     for(int j=0;j<(m.col);j++){
        //         result[(int)(col*i+j)]=m.matrix[(int)(col*i+j)]+this->matrix[(int)(col*i+j)];
        //     }
        // }
        // Matrix res(result,this->row, m.col);
        // return res;

    } 

    double Matrix::MultResult(Matrix const &m,int col,int row){
        double sum=0;
        for(int i=0;i<(m.row);i++){    
            for(int j=0;j<(m.col);j++){
              sum+=m.matrix[(unsigned int)(col*i+j)];
            }
        }
        return sum;
    }  
    
 istream &operator>>(istream &input, Matrix &m)
    {
        return input;
    }

    ostream &operator<<(ostream &out, const Matrix &m)
    {
        return out;
    }
    Matrix operator-(Matrix &m){
        return m;
    }
    Matrix operator*(double num, Matrix &m){
        return m;
    }
    Matrix operator+(Matrix &m){
        return m;
    }

};