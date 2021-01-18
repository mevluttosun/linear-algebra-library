#include <iostream>
#include "lal.h"
#include "math.h"
#include "time.h"
#include "cmath"

using namespace std;

double **createMatrix(int m,int n) {
          double **v =(double **)malloc(m*sizeof(double *));
          int i;

          for (i=0; i<m; i++) {
                    v[i] = (double *)malloc(n * sizeof(double));
          }

          return v;
}
double *createPointer(int n) {
          double *d = (double *)malloc(n * sizeof(double));
          int i;

                    //srand(time(NULL));
          for(i=0; i<n; i++) {

                    double a=(rand() %10);
                    a = a+1.0;
                    d[i]=a;
          }

          return d;
}
Matrix::Matrix(double *d,int row,int col) {
          this->entries=d;
          this->rows=row;
          this->cols=col;
}
void Matrix::print() {
          double **matrix =(double **)malloc(this->getRowCount()*sizeof(double *));
          int i,j;

          for (i=0; i<this->getRowCount(); i++) {
                    matrix[i] = (double *)malloc(this->getColCount()* sizeof(double));
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
Matrix::~Matrix() {}

Vector::Vector(double *d,int row):Matrix(d,row,1)  {
          int i,sum=0;

          for(i=0; i<row; i++) {
                    sum+=d[i]*d[i];
          }

          this->l2Norm=sqrt(sum);

}
Vector::~Vector() {}

Matrix transpoze(Matrix m) {
          double **matrix =(double **)malloc(m.getRowCount()*sizeof(double *));
          int i,j;

          for (i=0; i<m.getRowCount(); i++) {
                    matrix[i] = (double *)malloc(m.getColCount() * sizeof(double));
          }

          for(i=0; i<m.getRowCount(); i++) {
                    for(j=0; j<m.getColCount(); j++) {
                              matrix[ i ][ j ] = m.getEntries()[ i*m.getColCount() + j ];
                              //cout <<matrix[i][j]<<"   ";
                    }
          }
          double **transpoze =(double **)malloc(m.getRowCount()*sizeof(double *));

          for (i=0; i<m.getRowCount(); i++) {
                    transpoze[i] = (double *)malloc(m.getColCount() * sizeof(double));
          }

          for (int i = 0; i < m.getRowCount(); i++) {

                    for (int j = 0; j < m.getColCount(); j++) {
                              transpoze[j][i]=matrix[i][j];


                    }
          }

          double *d=(double *)malloc(m.getRowCount() * m.getColCount() *sizeof(double));
          int indx=0;

          for (int i = 0; i < m.getRowCount(); i++) {
                    for (int j = 0; j < m.getColCount(); j++) {
                              d[indx]=transpoze[i][j];
                              //cout<<indx<<" ";
                              indx++;
                    }
          }

          for (int i = 0; i < m.getRowCount() *m.getColCount(); i++) {
                    //cout<<d[i]<<" ";
          }

          Matrix result(d,m.getRowCount(),m.getColCount());
          return result;

}
Matrix *vectorArray2Matrix( Vector ** v,int row,int col) {
          int i,j;
          int index=0;
          double *d=(double *)malloc(row*col*sizeof(double));

          for(i=0; i<row; i++) {
                    for(j=0; j<col; j++) {
                              d[index]=v[i]->getEntries()[j];
                              index++;
                    }
          }

          Matrix *matrix=new Matrix(d,row,col);
          return matrix;
}
