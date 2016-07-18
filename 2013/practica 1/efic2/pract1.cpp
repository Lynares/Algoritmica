#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define UMBRAL_MS 200

void OrdenacionPorInsercion(int vector[], int n){//n es el numero de elementos 
//Vector es un vector de enteros
	int aux, j;

	for(int i=1; i<n; i++){
		j=i;
		aux=vector[i];
// se localiza el punto de insercion explorando hacia abajo
		while(j>0 && aux < vector[j-1]){
			vector[j]=vector[j-1];//Desplazamos los elementos hacia arriba para hacer espacio
			j--;
		}
	vector[j]=aux;
	}
}



int main(int argc, char *argv[]){
	  int elem, vector[500];
	  srand(time(0)); //inicializamos la semilla 
	  const int NUM_VECES = 1000;
	  time_t tantes,tdespues;
	  time_t tgen_antes,tgen_despues;
	  double tacu=0.0;
	elem=500;	  
	  time(&tantes) ;
	  for (int i=0;i<NUM_VECES;i++){
		    time(&tgen_antes); //capturamos el tiempo para saber cuanto tarda la generacion aleatoria
		    for (int j=0;j<500;j++)
			      vector[j]= random();
		    time(&tgen_despues);
		    tacu += difftime(tgen_despues,tgen_antes);
		   
		    OrdenacionPorInsercion(vector, elem);	      
		   
		    
	  }	    
	  time(&tdespues) ;
	  cout<< (difftime(tdespues,tantes)-tacu)/(double)NUM_VECES<<endl;

}	  

