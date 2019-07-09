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
	eonda(c,L,t,tfinal,N);
	return 0;
}

void eonda(double con, double longitud,double t0, double tf, int npuntos){
	ofstream outfile;
	outfile.open("cuerda.txt");

	double Aactual[npuntos];
	double Aold[npuntos];
	double Anew[npuntos];
	double A0=0.01;
	//Aold[0]=0.0;
	//A[npuntos-1]=0.0;
	//A[(npuntos/2)-1]=A0;


	double dx= (tf- t0)/(npuntos-1);
	double dt=dt=(dx*0.1)/con ;
	double s=con*(dt/dx);
	double tiempo[npuntos];

	tiempo[0]=t0;


	for(int i=1; i<npuntos ; i++)// para crear linspace con npuntos determinado
    {  
     tiempo[i]= tiempo[i-1]+dx;
    }

    for(int i=0; i<npuntos; i++)
    {
    	double m=(A0/(longitud/2));
  		if( i==0){
  			Aold[i]=0;
  		}
  		else if(i==npuntos-1){
  			Aold[i]=0;
  		}
  		else if (i<(npuntos/2)-1)
  		{
  			Aold[i]= i*dx*m;
  		}
  		else if(i>(npuntos/2)-1){
  			Aold[i]= -(i*dx*m)+(2*A0);
  		}
    }

    for(int i=0; i<npuntos; i++)
    {
    	outfile  << tiempo[i]  << "  " << Aold[i] << endl;
    }
	outfile.close();
}