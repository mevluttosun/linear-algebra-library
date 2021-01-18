#include <iostream>
#include "lal.h"
#define M 3
#define P 3
using namespace std;

int main() {


           Vector *vectorDizi= (Vector *)malloc(P*sizeof(Vector));                    //P adet M sayida vektor tutuyor
           int i;
           for(i=0;i<P;i++){
		Vector  v(createPointer(M),M);
		vectorDizi[i]=v;
           }
           Matrix *MatrixDizi= (Matrix *)malloc(4*sizeof(Matrix));

           Vector v1(createPointer(3),3);
           Vector v2(createPointer(3),3);
           Matrix m1(createPointer(3*3),3,3);
           Matrix m2(createPointer(3*3),3,3);
           MatrixDizi[0]=v1;
           MatrixDizi[1]=v2;
           MatrixDizi[2]=m1;
           MatrixDizi[3]=m2;

           Matrix toplama=MatrixDizi[3]+MatrixDizi[2];
           cout<<"Matrix 1"<<endl;
           MatrixDizi[2].print();puts("");
           cout<<"Matrix 2"<<endl;
           MatrixDizi[3].print();puts("");
           cout<<"Toplama"<<endl;
           toplama.print();puts("");
	cout<<"Cikarma"<<endl;
	Matrix cikarma=MatrixDizi[3]-MatrixDizi[2];
          cikarma.print();puts("");
          cout<<"Carpma"<<endl;
	Matrix carpma=MatrixDizi[3]*MatrixDizi[2];
          carpma.print();puts("");
          cout<<"Esit"<<endl;
          bool result=MatrixDizi[2]==MatrixDizi[2];

          if(result==0) { cout<<"yanlis" <<endl;}

	if(result==1) { cout<<"dogru" <<endl; }puts("");
	  result=MatrixDizi[3]==MatrixDizi[2];
	 if(result==0) { cout<<"yanlis" <<endl;}
	if(result==1) { cout<<"dogru" <<endl; }puts("");
           cout<<"Vector artirma"<<endl;
	vectorDizi[0].print();puts("");
	cout<<"Artirilmis Hali "<<endl;
	++vectorDizi[0];
	vectorDizi[0].print();puts("");
	cout<<"Transpoz"<<endl;
	cout<<"Matris"<<endl;
	MatrixDizi[3].print();puts("");
	cout<<"Transpozu"<<endl;
	transpoze(MatrixDizi[3]).print();puts("");

	cout<<"Norm"<<endl;
	vectorDizi[0].print();puts("");
	cout<<vectorDizi[0].getNorm()<<endl;

	//Vector trans=transpoze(dynamic_cast<Vector>(Matrix));       //CAST GEREKIYOR

          return 0;
}
