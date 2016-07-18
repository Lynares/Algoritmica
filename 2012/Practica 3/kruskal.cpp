#include <iostream>
#include <vector>

using namespace std;

int cn=4; //cantidad de nodos
const int INF=999999;
int adyacencia[4][4]={{INF,2,INF,3},
                      {2,INF,INF,INF},
                      {INF,INF,INF,3},
                      {3,INF,3,INF}
}; //matriz de adyacencia




// Devuelve la matriz de adyacencia del árbol mínimo.
vector< vector<int> > kruskal(){
    vector< vector<int> > arbol(cn);
    vector<int> pertenece(cn); // indica a que árbol pertenece el nodo
 //arbol es la solucion
//cn cantidad de nodos, filas y columnas matriz cuadrada simetrica
//arcos los arcos que ahora mismo tenemos
    for(int i = 0; i < cn; i++){
       arbol[i]= vector<int>(cn,INF);
       pertenece[i] = i;
    }
 
    int nodoA;
    int nodoB;
    int arcos = 1;
    while(arcos < cn){
        // Encontrar  el arco mínimo que no forma ciclo y guardar los nodos y la distancia.
        int min = INF;
        for(int i = 0; i < cn; i++)
            for(int j = 0; j < cn; j++)
                if(min > adyacencia[i][j] && pertenece[i] != pertenece[j]){ //pertenece[i]=pertenece[j] cuando se conectan dos arcos los perteneces son iguales | si tienen el mismo valor significa que estan conectados
                    min = adyacencia[i][j];
                    nodoA = i;
                    nodoB = j;
                }
 
        // Si los nodos no pertenecen al mismo árbol agrego el arco al árbol mínimo.
        if(pertenece[nodoA] != pertenece[nodoB]){
            arbol[nodoA][nodoB] = min;
            arbol[nodoB][nodoA] = min;
 
            // Todos los nodos del árbol del nodoB ahora pertenecen al árbol del nodoA.
                int temp = pertenece[nodoB];
                pertenece[nodoB] = pertenece[nodoA];
                for(int k = 0; k < cn; k++)
                        if(pertenece[k] == temp)
                                pertenece[k] = pertenece[nodoA];
 
            arcos++;
        }
    }
    return arbol;
}

void Imprimir(vector< vector<int> > mat, int fc){
for(int i=0; i<fc; i++){
 for(int j=0; j<fc; j++){
	if(i<=j)
	if(mat[i][j]!=INF){
		cout << "El nodo " << i << " está conectado con el nodo " << j << endl;
	}
 }

}
}

int main(){

vector < vector<int> > solucion=kruskal();
Imprimir(solucion,cn);
}
