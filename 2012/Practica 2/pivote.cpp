#include <iostream>

using namespace std;

void Intercambiar(int *&v, int i, int l){
   int aux;
   aux=v[i];
   v[i]=v[l];
   v[l]=aux;

 }//Fin Intercambiar

void Pivote(int *v,int i, int j, int &l){

 int p;
 int k;
 
 p=v[i];
 k=i;
 l=j+1;
 while((v[k]<=p) && (k<j)){
   k=k+1;
 }
 while(v[l]>p){
   l=l-1;
 }

 while(k<l){
   Intercambiar(v,k,l);
   while(v[k]<=p){
     k=k+1;
   }
   while(v[l]>p){
     l=l-1;
   }
 }

 Intercambiar(v,i,l);

}//Fin pivote

int Seleccion(int *v,int tam,int s){
 int i,j,l;
 i=0;
 j=tam;
 do{
   Pivote(v,i,j,l);
   if(s<l){
     j=l-1;
   }else if(s>l) {
     i=l+1;
   }
 }while(l!=s);

 return v[l];

}//Fin seleccion




int main(){


int tam;
cout << "introduce tamaño: ";
cin >> tam;
int v[tam];
cout << "Introduce elementos del vector: \n";
for(int i=0;i<tam;i++){
 cin >> v[i];
}
int mediana=tam/2;
cout << "La mediana del vector es: " << Seleccion(v,tam,mediana) << endl;

}//Fin main


