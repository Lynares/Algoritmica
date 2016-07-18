#include <iostream>
#include <cstdlib>
using namespace std;

bool BusquedaBinaria(int *vec, int tam, int dato){

	int centro, inf=0, sup=tam-1;
	while(inf<=sup){
//		centro=((sup-inf)/2)+inf; //Division entera: se trunca la fraccion
		centro=((sup-inf)/3)+inf; //Para que divida en un tercio

		if(vec[centro]==dato){
			cout << "La posicion es: " << centro << endl;
			return true;

		}else if(vec[centro]>dato)
		sup=centro-1;
		else 
		inf=centro+1;
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

if(BusquedaBinaria(vec,tam,dato)){
cout << dato<<endl;
	for(int i=0; i<tam; i++)
		cout <<"pos: " << i << " es: " << vec[i] << endl;
}

}
