#include <iostream>
#include "lal.h"
#include "math.h"
using namespace std;

Matrix::Matrix(double *d,int row,int col) {
          this->entries=d;
          this->rows=row;
          this->cols=col;
}

void Matrix::print() {
          double **matrix =(double **)malloc(this->rows*sizeof(double *));
          int i,j;

          for (i=0; i<this->rows; i++) {
                    matrix[i] = (double *)malloc(this->cols * sizeof(double));
          }

          for(i=0; i<this->rows; i++) {
                    for(j=0; j<this->cols; j++) {
                              matrix[ i ][ j ] = this->entries[ i*this->cols + j ];
                    }
          }

          for(i=0; i<this->rows; i++) {
                    for(j=0; j<this->cols; j++) {
                              printf("%.2f  \t",matrix[i][j]);
                    }

                    puts("");
          }

}

 Matrix::~Matrix() {
          cout<<"Matrix silindi "<<endl;
}
Vector::Vector(double *d,int row):Matrix(d,row,1)  {
                    int i,sum=0;

                    for(i=0; i<row; i++) {
                              sum+=d[i]*d[i];
                    }

                    this->l2Norm=sqrt(sum);

}
Vector::~Vector() {
          cout<<"Vector silindi"<<endl;
}
