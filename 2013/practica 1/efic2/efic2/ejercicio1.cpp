#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define UMBRAL_MS 200
/**
@brief Ordenacion Burbuja
@param T: vector con los elelmentos a ordenar
@param inicial: limite inferior del rango a ordenar sobre T
@param final: limite superior del rango a ordenar sobre T
@note Los elementos en T quedan ordenados dede menor a mayor
**/
 
void burbuja(long int T[], int inicial, int final)

{

long int aux;

for (int i = inicial; i < final - 1; i++)

 for (int j = final - 1; j > i; j--)

  if (T[j] < T[j-1]){

	  aux = T[j];

	  T[j] = T[j-1];

	  T[j-1] = aux;
   }

}
/**
@brief Une dos vectores en un tercer vector. En este tercer vecto los elmentos quedan ordenados
@param T: vector donde se deja la union de los otros dos vectores
@param inicial: limite inferior donde colocar en T los elementos unidos de los dos vectores
@param final: limite superior (no se incluye) donde termina los elementos unidos de los dos vectores
@param U: vector a unir
@param V : vector a unir
@note Los elemento en T quedan ordenados de menor a mayor en el rango[inicial, final-1]
*/
void fusion(long int T[], int inicial, int final,long  int U[],long int V[]){

int j = 0;

int k = 0;

 for (int i = inicial; i < final; i++){

  if (U[j] < V[k]) {

	  T[i] = U[j];
	  j++;
  } 
  else{

	  T[i] = V[k];
	  k++;

  }

}
}

/**
@brief Ordenación de un vector mediante la técnica de Mezcla mergesort
@param T: vector con los elementos a ser ordenados
@param inicial: limite inferior del rango de elementos en T que deseamos ordenar
@param final: limite superior del rango de elementos en T que deseamos ordenar
@note Los elementos en T quedan ordenados de mayor a menor
*/
void mergesort(long int T[], int inicial, int final){

   if (final - inicial < UMBRAL_MS){

        burbuja(T, inicial, final);
   }	

   else {

	  int k = (final - inicial)/2;

	  long int * U = new long int [k - inicial + 1];

	  int l, l2;

	  for (l = 0, l2 = inicial; l < k; l++, l2++)

		    U[l] = T[l2];

	  

	  long int * V = new long int [final - k + 1];

	  for (l = 0, l2 = k; l < final - k; l++, l2++)

		    V[l] = T[l2];

	  

	  mergesort(U, 0, k);

	  mergesort(V, 0, final - k);

         fusion(T, inicial, final, U, V);

	 delete [] U;

	 delete [] V;

  }

}
int main(int argc, char *argv[]){
	  if (argc!=2){
		    cout<<"Los parametros son:"<<endl;
		    cout<<"El número de elementos del vector";
		    return 0;
	  }
	  int n = atoi(argv[1]); //la talla 
	  
	  long int *T = new long int[n];
	  srand(time(0)); //inicializamos la semilla 
	  const int NUM_VECES = 1000;
	  time_t tantes,tdespues;
	  time_t tgen_antes,tgen_despues;
	  double tacu=0.0;
	  
	  time(&tantes) ;
	  for (int i=0;i<NUM_VECES;i++){
		    time(&tgen_antes); //capturamos el tiempo para saber cuanto tarda la generacion aleatoria
		    for (int j=0;j<n;j++)
			      T[j]= random();
		    time(&tgen_despues);
		    tacu += difftime(tgen_despues,tgen_antes);
		   
		    mergesort(T,0,n);	      
		   
		    
	  }	    
	  time(&tdespues) ;
	  cout<< (difftime(tdespues,tantes)-tacu)/(double)NUM_VECES<<endl;
	  delete []T;
}	  
			      
	  
	  
	  
	  

