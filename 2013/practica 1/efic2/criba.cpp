#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define UMBRAL_MS 200

void criba(bool m[], int tam){
    m[0] = false;
    m[1] = false;
    for(int i = 2; i <= tam; ++i) 
	m[i] = true;
 
    for(int i = 2; i*i <= tam; ++i) {
        if(m[i]) {
            for(int h = 2; i*h <= tam; ++h)
                m[i*h] = false;
        }
    }
	for(int i=0; i<tam; ++i)
		cout << m[i] << " " ;
	cout << endl; 	
}

int main(){

int tam;
bool m[tam];
	  srand(time(0)); //inicializamos la semilla 
	  const int NUM_VECES = 1000;
	  time_t tantes,tdespues;
	  time_t tgen_antes,tgen_despues;
	  double tacu=0.0;

	  time(&tantes);
	  for (int i=0;i<NUM_VECES;i++){
		    time(&tgen_antes); //capturamos el tiempo para saber cuanto tarda la generacion aleatoria
//	    for (int j=0;j<10;j++)
//			      tam= random();
		    time(&tgen_despues);
		    tacu += difftime(tgen_despues,tgen_antes);
		   
		   criba(m, tam);
		   
		    
	  }	    
	  time(&tdespues) ;
	  cout<< (difftime(tdespues,tantes)-tacu)/(double)NUM_VECES<<endl;
	  

}
