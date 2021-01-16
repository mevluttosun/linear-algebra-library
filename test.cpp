#include <iostream>
#include "lal.h"
using namespace std;

int main() {
	double *d=(double *)malloc(5*sizeof(double));
	d[0]=3.1;d[1]=5.6;d[2]=9.2;d[3]=2.4;d[4]=5.2;d[5]=6.3;
	Vector *v = new Vector(d,5);
	v->print();
	Matrix *m= new Matrix(d,3,3);
          return 0;
}
