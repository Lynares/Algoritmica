#include <iostream>

using namespace std;

//Funcion para crear matriz dinamica

int **CrearMatriz(int fil, int col){
 int **m;
 m=new int *[fil];
 for(int i=0;i<fil;i++)
    m[i]=new int [col];
 return m;
}//Fin CrearMatriz

//Funcion para calcular el minimo de dos numeros

int Minimo(int x, int y){
 if(x<y){
   return x;
 }else{
   return y;
 }
}//Fin Minimi

//Funcion que nos devuelve el cambio optimo.

int Cambio(int tam,int *nm, int cant){

 int **matriz=CrearMatriz(tam+1,cant+1);

  for(int i=0;i<tam+1;i++)
    for(int j=0;j<cant+1;j++)
       matriz[i][j]=0;

  for(int i=0;i<tam+1;i++){
    matriz[i][0]=0;
  }

  for(int j=1;j<cant+1;j++){
     matriz[0][j]=999999;
  }

  for(int i=1;i<=tam;i++){
    for(int j=1;j<=cant;j++){
        if(nm[i-1]>j){ //Vemos si la moneda es superior a la cantidad a devolver.
	  matriz[i][j]=matriz[i-1][j];
	}else{          
	  int minimo=0;
          minimo=Minimo(matriz[i-1][j],matriz[i][j-nm[i-1]]+1);
          matriz[i][j]=minimo;
        }
      }
  }
int solucion[tam];
for(int i=0; i<tam; i++){
 solucion[i]=0;
}
int k=cant, y=tam;
  while(k!=0 && y!=0){
     if(matriz[y][k]==matriz[y-1][k]){
	y--;
      }else{
	solucion[y-1]=solucion[y-1]+1;
	k=k-nm[y-1];
      }
  }
  for(int p=0; p<tam; p++){
	cout << "Usamos " << solucion[p] << " de valor " << nm[p] << endl;
  }

 return matriz[tam][cant];
 
}//Fin cambio


int main(){
//Ejemplo de las transparencias usadas en clase para exponer este problema.
int cant;
int nm[5]={1,2,5,10,15};
cout << "Introduce el valor a devolver: ";
cin >> cant;
cout << "El cambio es: " << Cambio(5,nm,cant) << endl;

}//Fin main
