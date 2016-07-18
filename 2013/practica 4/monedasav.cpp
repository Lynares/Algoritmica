#include <iostream>

using namespace std;

void CambioVoraz(int cantidad, int valores[], int *&solucion, int tam){
	int devuelta=0;
	int h=tam;

	while(devuelta!=cantidad){
		while(valores[h]>(cantidad-devuelta) && (h>0)){
			h--;
		
			solucion[h]=((cantidad-devuelta)/valores[h]);
			devuelta= devuelta + (valores[h]*solucion[h]);
		}
	}
}

int main(){
	const int tam=5;
	int cantidad=32;
	int valores[tam]={1,5,10,12,25};
	int *solucion;
	solucion=new int [tam];
	for(int i=0; i<tam; i++){
		solucion[i]=0;
	}
	cout << "Cantidad: " << cantidad << endl;
	CambioVoraz(cantidad, valores,solucion,tam);
	for(int i=0;i<tam; i++){
		if(solucion[i]!=0)
		cout << solucion[i] << " de " << valores[i] << endl;
	}
}
