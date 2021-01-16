#ifndef LAL_H
#define LAL_H

class Matrix{

private:
	double *entries;
	int rows,cols;

public:
	Matrix(double *,int,int);
	~Matrix();
	void print(void);

};
class Vector:public Matrix{
public:
	Vector(double *,int);
	~Vector();
	void print(void);
	double l2Norm();
};

