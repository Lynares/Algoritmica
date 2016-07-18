#include <iostream>
#include <cstdlib>
using namespace std;


void criba(bool *m, int tam){
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
}

int main(int argc, char *argv[]){

int tam=atoi(argv[1]);
bool m[tam];
	  srand(time(0)); //inicializamos la semilla 
	  const int NUM_VECES = 1000;
	  time_t tantes,tdespues;
	  double tacu=0.0;

	  time(&tantes);
	  for (int i=0;i<NUM_VECES;i++){
		   criba(m, tam);
		   
		    
	  }	    
	  time(&tdespues) ;
	  cout<< (difftime(tdespues,tantes))/(double)NUM_VECES<<endl;
	  

}
