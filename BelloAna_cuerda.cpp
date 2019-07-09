#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

void eonda(float t0, float tf, int npuntos);

int main(){

	float L=1.0;
	float dx=0.01;
	float c= 300.0;
	int N = 100;
	float dt=0.01;
	float Aactual[N];
	float Aold[N];
	float Anew[N];
	float s=c*(dt/dx);
	float t =0.0;
	float tfinal=0.1;
	eonda(t,tfinal,N);
	return 0;
}

void eonda(float t0, float tf, int npuntos){
	ofstream outfile;
	outfile.open("cuerda.txt");

	float dx= (tf- t0)/(npuntos-1);
	float tiempo[npuntos];
	tiempo[0]=t0;


	for(int i=1; i<npuntos ; i++)// para crear linspace con npuntos determinado
    {  
     tiempo[i]= tiempo[i-1]+dx;
    }

    for(int i=0; i<npuntos; i++)
    {
    	outfile  << tiempo[i] << endl;
    }
	outfile.close();
}