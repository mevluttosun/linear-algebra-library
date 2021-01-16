#define LAL_H

class Matrix{

private:
	double *entries;
	int rows,cols;

public:
	Matrix(double *,int,int);
	~Matrix();
	void print();

};
class Vector:public Matrix{
	double l2Norm;
public:
	Vector(double *,int);
	~Vector();
	//void print(void);

};

