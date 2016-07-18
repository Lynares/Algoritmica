#include <iostream>
#include <cstdlib>
using namespace std;

int Minimo(int a, int b){
	if (a<b)
		return a;
	else 
		return b;
}

int Maximo(int a, int b){
	if (a>b)
		return a;
	else 
		return b;
}

int Mediana(int *v1, int inicio_v1, int tamano_v1, int *v2, int inicio_v2, int tamano_v2){

	int posv1, posv2, numeles;
//Caso base
	if((inicio_v1>=tamano_v1)&&(inicio_v2>=tamano_v2))
		return Minimo(v1[tamano_v1],v2[tamano_v2]);
//En caso de que sean vectores de dos elementos	
	numeles=tamano_v1-inicio_v1+1;
	if(numeles==2){
		if(v1[tamano_v1]<v2[inicio_v2])
			return v1[tamano_v1];
		else if(v2[tamano_v2]<v1[inicio_v1])
			return v2[tamano_v2];
		else 
			return Maximo(v1[inicio_v1],v2[inicio_v2]);
	}
//Caso general
	numeles=(numeles-1)/2;
	posv1=inicio_v1+numeles;
	posv2=inicio_v2+numeles;

	if(v1[posv1]<v2[posv2])
		return v1[posv1];
	else if(v1[posv1]<v2[posv2])
		return Mediana(v1,tamano_v1-numeles,tamano_v1,v2,inicio_v2,inicio_v2+numeles);
	else
		return Mediana(v1,inicio_v1,inicio_v1+numeles,v2,tamano_v2-numeles,tamano_v2);
}
	
void burbuja(int T[], int inicial, int final){

int aux;

for (int i = inicial; i < final - 1; i++)
 for (int j = final - 1; j > i; j--)
  if (T[j] < T[j-1]){
	  aux = T[j];
	  T[j] = T[j-1];
	  T[j-1] = aux;
   }
}


int main(){
int *v1, *v2, n=9;
v1=new int [n];
v2=new int [n];
for(int i=0; i<n; i++){
	v1[i]=(rand()%20)*12;
	v2[i]=(rand()%15)*20;
}
burbuja(v1,0,n);
burbuja(v2,0,n);

for(int u=0; u<n; u++){
	cout << v1[u] << " ";
}
cout << endl;
for(int e=0; e<n; e++){
	cout << v2[e] << " ";
}
cout << endl;
cout << Mediana(v1,0,n,v2,0,n) << endl;


}
