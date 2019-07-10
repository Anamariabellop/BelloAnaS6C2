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
	double Apresente[npuntos];
	double A0=0.01;
	double dx=0.005;// dx de la ecuacion
	double dt=(tf-t0)/(npuntos-1); //Para linspace de tiempo 
	double deltat=(dx*0.9)/con;// de la ecuacion
	double s=con*(deltat/dx);
	double tiempo[npuntos];
	double delta= (longitud)/(npuntos-1);//pendientes condiciones iniciales.
	double m=(A0)/(longitud/2.0);
	double L[npuntos];
	double matrizdatos[npuntos][10];
	L[0]=0.0;
	tiempo[0]=t0;


	//condiciones iniciales con extremos fijos.

	for(int i=1; i<npuntos ; i++)// para crear linspace con npuntos determinado
    {  
     tiempo[i]= tiempo[i-1]+dt;
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

    //Para iniciar.
    double k=(con*(deltat/dx));
    for(int i=0; i< npuntos;i++){
    	Anew[i]=  (2.0*Aold[i] + ((k*k)*(Aold[i+1]+Aold[i-1]-(2.0*Aold[i]))))/2;
    	Aactual[i]=Anew[i];//Actualizo actual con respecto al nuevo.
    }
    for(int i=0; i<npuntos; i++)
    {
    	outfile  << L[i] << "  " << i << "  " << Aold[i] << "  " << Anew[i]<< "  " << Aactual[i]<< endl;
    }

	outfile.close();

	ofstream outfile2;
	outfile2.open("cuerda2.txt");

    for(int i=0; i<10; i++){
    	for(int j=0; i<npuntos; i++){
    		Anew[j]= ((2.0*Aactual[j]) + ((k*k)*(Aactual[j+1]+Aactual[j-1]-(2.0*Aactual[j]))))/2;	
    	}
    }

    for(int i=0; i< npuntos; i++){
    	Aold[i]=Aactual[i];//Actualizo el viejo con respecto a actual.
    	Aactual[i]=Anew[i];//Actualizo actual con respecto a nuevo.
    }

    for(int i=0; i<10;i++){
    	for(int i=0; i<npuntos; i++)
    	{
    	outfile2  << L[i] << "  " << i << "  " << Aold[i] << "  " << Anew[i]<< "  " << Aactual[i]<< endl;
    	}

    }
    

    outfile2.close();

    
}