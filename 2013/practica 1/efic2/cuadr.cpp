#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
#define UMBRAL_MS 200
void Cuadrado(int v[], int tam){
for(int i=0; i<tam; i++)
	v[i]=i*i;
for(int j=0; j<tam; j++)
	cout << v[j] << " ";

} 

int main(){
	int tam= 20;
	int v[tam];
srand(time(0)); //inicializamos la semilla 
	  const int NUM_VECES = 1000;
	  time_t tantes,tdespues;
	  time_t tgen_antes,tgen_despues;
	  double tacu=0.0;

	  time(&tantes);
	  for (int i=0;i<NUM_VECES;i++){
		    time(&tgen_antes); //capturamos el tiempo para saber cuanto tarda la generacion aleatoria
	    for (int j=0;j<200;j++)
		      tam= 20;
		    time(&tgen_despues);
		    tacu += difftime(tgen_despues,tgen_antes);
		   
		   Cuadrado(v, tam);
		   
		    
	  }	    
	  time(&tdespues) ;
	  cout<< (difftime(tdespues,tantes)-tacu)/(double)NUM_VECES<<endl;
	  }
