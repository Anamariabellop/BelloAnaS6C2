#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

void eonda(double const, double longitud,double t0, double tf, int npuntos);

int main(){

	double L=1.0;
	double dx=0.01;
	double c= 300.0;
	int N = 100;
	double t =0.0;
	double tfinal=0.1;
	eonda(c,L,t,tfinal,101);
	return 0;
}

void eonda(double con, double longitud,double t0, double tf, int npuntos){
	ofstream outfile;
	outfile.open("cuerda.txt");

	double Aactual[npuntos];
	double Aold[npuntos];
	double Anew[npuntos];
	double A0=0.01;
	
	double dx= (tf- t0)/(npuntos-1);
	double dt=(dx*0.1)/con;
	double s=con*(dt/dx);
	double tiempo[npuntos];
	double delta= (longitud)/(npuntos-1);
	double m=(A0)/(longitud/2.0);
	double L[npuntos];
	L[0]=0.0;
	tiempo[0]=t0;


	//condiciones iniciales con extremos fijos.

	for(int i=1; i<npuntos ; i++)// para crear linspace con npuntos determinado
    {  
     tiempo[i]= tiempo[i-1]+dx;
     L[i]=L[i-1]+delta;
    }

    for(int i=0; i<(npuntos/2); i++)
    {
  		Aold[i]=i*delta*m;	
    }

    for(int i=(npuntos/2); i<npuntos+1; i++)
    {
    	Aold[i]= ((-m)*i*delta)+(2.0*A0);
    }


    /*for(int i=0; i<npuntos; i++)
    {
    	outfile  << tiempo[i] << "  " << i << "  " << Aold[i] << endl;
    }*/

	outfile.close();
}