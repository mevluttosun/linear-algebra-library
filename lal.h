#define LAL_H

class Matrix {

private:
          double *entries;
          int rows,cols;

public:
          Matrix(double *,int,int);
          ~Matrix();
          int getRowCount() const {
                    return this->rows;
          }
          int getColCount() const {
                    return this->cols;
          }
          double *getEntries() const {
                    return this->entries;
          }
          void print();
          Matrix operator+(const Matrix& M) {
                    int i;
                    double *d=(double *)malloc(this->getColCount() * this->getRowCount() * sizeof(double));

                    for(i = 0; i < getRowCount()*this->getColCount() ; i++) {
                              d[i]=this->entries[i] +M.getEntries()[i];

                    }

                    return Matrix(d,getRowCount(),getColCount());
          } Matrix operator - (const Matrix& M) {
                    int i;
                    double *d=(double *)malloc(this->getColCount() * this->getRowCount() * sizeof(double));

                    for(i = 0; i < this->getRowCount()*this->getColCount() ; i++) {
                              //std::cout<<this->getRowCount()*this->getColCount()<<std::endl;
                              d[i]=this->entries[i]-M.getEntries()[i];
                    }

                    return Matrix(d,getRowCount(),getColCount());
          }
          Matrix operator * (const Matrix& M) {
                    int i;
                    double *d=(double *)malloc(this->getColCount() * this->getRowCount() * sizeof(double));

                    for(i = 0; i < this->getRowCount()*this->getColCount() ; i++) {
                              d[i]=this->entries[i]*M.getEntries()[i];
                    }

                    return Matrix(d,getRowCount(),getColCount());
          }
          bool operator ==(const Matrix& M) {
                    int i;
                    bool control=false;

                    for(i = 0; i < this->getRowCount()*this->getColCount() ; i++) {
                              if(this->entries[i]==M.getEntries()[i]) {
                                        control =true;

                              } else if(this->entries[i]!=M.getEntries()[i]) {
                                        control =false;
                                        break;
                              }
                    }

                    return control;
          }
};
class Vector:public Matrix {
          double l2Norm;
public:
          Vector(double *,int);
          ~Vector();
          double getNorm(){return this->l2Norm;}
          Vector operator ++ () {
                    int i;
                    for(i = 0; i < this->getRowCount(); i++) {
                              //std::cout<<getEntries()[i]<<  std::endl;
                              this->getEntries()[i]+=1.0;
                    }

                    return Vector(this->getEntries(),getRowCount());
          }

          //void print(void);

};
Matrix transpoze(Matrix );
double *createPointer(int );

