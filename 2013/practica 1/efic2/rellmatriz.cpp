#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define UMBRAL_MS 200

void RellenaAuto(int **m, int tam){

 for(int i=0; i<tam; i++)
  for(int j=0; j<tam; j++)
   m[i][j]=rand()%20; //Inicia Matriz entre 0 y 20 aleatoriamente

}
	
void **SumaMatrices(int **x, int **y, int **&res, int tam){
	for(int i=0; i<tam; i++)
   		 for(int j=0; j<tam; j++)
  			res[i][j]=x[i][j]+y[i][j];
}

int main(int argc, char *argv[]){

       int tam= atoi(argv[1]);
       int **matriz, **matriz2, **matriz3;
//Creacion de la matriz
       matriz=new int *[tam];
       for(int i=0; i<tam; i++)
          matriz[i]=new int [tam];
RellenaAuto(matriz, tam);
matriz2=new int *[tam];
       for(int i=0; i<tam; i++)
          matriz2[i]=new int [tam];
RellenaAuto(matriz2, tam);

matriz3=new int *[tam];
       for(int i=0; i<tam; i++)
          matriz3[i]=new int [tam];
RellenaAuto(matriz3, tam);


	  srand(time(0)); //inicializamos la semilla 
	  const int NUM_VECES = 1000;
	  time_t tantes,tdespues;
	  double tacu=0.0;

	  time(&tantes);
	  for (int i=0;i<NUM_VECES;i++)
		SumaMatrices(matriz,matriz2,matriz3,tam);
	  time(&tdespues) ;
	  cout<< (difftime(tdespues,tantes))/(double)NUM_VECES<<endl;
	for(int j=0; j<tam; j++)
		delete[] matriz[j];
	delete [] matriz;
for(int j=0; j<tam; j++)
		delete[] matriz2[j];
	delete [] matriz2;
for(int j=0; j<tam; j++)
		delete[] matriz3[j];
	delete [] matriz3;

}
