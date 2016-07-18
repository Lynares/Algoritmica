#include <iostream>
#include <cstdlib>

using namespace std;

int **Crear(int fils, int cols){
	int **matriz;
	matriz=new int *[fils];
	for(int i=0; i<fils; i++)
		matriz[i]=new int [cols];
	return matriz;
}

int CambioDinamico(int devolucion, int monedas[], int numero_monedas){

	int **cambio=Crear(numero_monedas+1, devolucion+1);
	int **aux=Crear(numero_monedas+1, devolucion+1);
	int i, j;	
	for(i=0; i<numero_monedas+1; i++)
		for(j=0; j<devolucion+1; j++)
			aux[i][j]=0;

	for(i=0; i<numero_monedas; i++)
		cambio[i][0]=0;

	for(i=1; i<=devolucion; i++)
		cambio[0][i]=100000;

	for(i=1; i<=numero_monedas; i++)
		for(j=1; j<=devolucion; j++){

			if(monedas[i-1]>j)
				cambio[i][j]=cambio[i-1][j];
			else{
				int menor=0;
				if(cambio[i-1][j]<cambio[i][j-monedas[i-1]] +1)
					menor=cambio[i-1][j];
				else
					menor=cambio[i][j-monedas[i-1]]+1;

				cambio[i][j]=menor;
				aux[i][j]=1;
			}
		}
			
		return cambio[numero_monedas][devolucion];
}


int main(int argc, char *argv[]){
	int numero_monedas=5;
	int monedas[5]={1,5,10,12,25};
	int cantidad=32;
	cout << "Cuantas monedas necesitamos: " << CambioDinamico(cantidad, monedas,numero_monedas) << " monedas" << endl;



}
