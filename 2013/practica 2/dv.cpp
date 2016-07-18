#include <iostream>
#include <cstdlib>
using namespace std;

bool BusquedaUnTercio(int *vec, int tam, int dato){

	int tercio, inf=0, sup=tam-1;
	while(inf<=sup){

		tercio=((sup-inf)/3)+inf; //Para que divida en un tercio

		if(vec[tercio]==dato){
			cout << "La posicion es: " << tercio << endl;
			return true;

		}else if(vec[tercio]>dato)
		sup=tercio-1;
		else 
		inf=tercio+1;
	}
	return false;
}

void RellenaVector(int *vec, int tam){
	for(int i=0; i<tam; i++)
		vec[i]=(i+2)*12;
}

int main(int argc, char *argv[]){
int *vec, tam, dato;
if(argc!=2)
	cout << "MAL" << endl;
tam=atoi(argv[1]);
vec=new int [tam];
RellenaVector(vec, tam);

dato=rand()%20*12;

if(BusquedaUnTercio(vec, tam, dato)){
cout << dato<<endl;
	for(int i=0; i<tam; i++)
		cout <<"pos: " << i << " es: " << vec[i] << endl;
}

}
