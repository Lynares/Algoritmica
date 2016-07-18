#include <iostream>
#include <cstdlib>
using namespace std;

void Camionero(int n, int *gasolineras, int tam, bool *&sol){
	int que_gasolinera=-1;
	int numero_km=0;
	do{
	  do{
	  	que_gasolinera++;
		numero_km+=gasolineras[que_gasolinera];
		}while( (numero_km<n) && (que_gasolinera<tam) );
	  if(numero_km>n){
	    que_gasolinera--;
	    sol[que_gasolinera]=true;
            numero_km=0;
	  }
	}while(que_gasolinera<tam);
}

int main(){
	const int tam=10; 
	int n=120;

	int *gasolineras;//[tam]={20,30,50,100,45,10,90,70,10,10};
	gasolineras=new int [tam];

	for(int h=0; h<tam; h++)
	gasolineras[h]=rand()%n;

	cout << "Numero de gasolineras: " << tam << endl;
	cout << "Numero de kilometros sin repostar: " << n << endl;

	for(int k=0; k<tam; k++){
	cout << "Hasta la gasolinera nº " << k << ": " << gasolineras[k] << " km." << endl;

	}

	bool *sol;
	sol= new bool [tam-1]; //Le ponemos tam-1 porque el ultimo tramo sera el destino.
	for(int i=0; i<tam-1; i++)
		sol[i]=false;
	Camionero(n, gasolineras, tam, sol);

	for(int j=0; j<tam-1; j++){
	cout << " Gasolinera: " << j << endl;
		cout << sol[j] << endl;
	}


}

