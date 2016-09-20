#include "graph.h"



int main(int argc, char const *argv[])
{
	
	int filas;
	int columnas;
	int cantidadParedes;

	cin >> filas >> columnas >> cantidadParedes;

	Grafo g = Grafo();


	//g.leer(filas, columnas);


	return 0;
}



Grafo::Grafo(){
	_cantnodos= 0;
	_nodos = vector<Nodo*>();
}

Grafo::Nodo* Grafo::vecino(int id, int i){
	int s = _nodos[id]->vecinos[i].second;
	return _nodos[s];
}

int Grafo::caminoMinimo(int origen, int destino, int P){
	_nodos[origen]->distancia = 0;
	queue<pair<int, int> > q;
	q.push(pair<int, int> (origen, P));
	while(! q.empty()){
		pair<int, int> actual = q.front();
		 q.pop();
		int pAux;
		for (int i = 0; i < _nodos[actual.first]->vecinos.size(); ++i){
			pAux = actual.second;
			if(vecino(actual.first, i)->distancia == -1 and (!(_nodos[actual.first]->vecinos[i].first == 2)) or pAux > 0 ){
				if(_nodos[actual.first]->vecinos[i].first == 2)	pAux--;
				 vecino(actual.first, i)-> distancia = _nodos[actual.first]->distancia + 1;

				 q.push(pair<int, int> (vecino(actual.first, i) -> id, pAux));
			}
			
		}
	}

	return _nodos[destino]->distancia;


}

/*Grafo::Grafo(int cantnodos, int id): _cantnodos(cantnodos){
   list<int> l (cantnodos,0);


   //vector<list<int> > lista (cantnodos,l);
  // _lista = lista;
}*/

/*void mostrar(int filas, int columnas, vector<vector<char> > matriz){

cout<<"------------------"<<endl;
    for(int i=0;i<filas ;i++){
        cout<<"[";
        for(int j=0;j<columnas;j++){
         if(j!=columnas-1){
        cout<<matriz[i][j]<<",";
        }else{
        cout<<matriz[i][j]<<"]"<<endl;
        	}
		}


}
cout<<"------------------";
}

void Grafo::leer(int filas, int columnas){
	
	vector<char> v (columnas);
	vector<vector<char> > matriz (filas, v);
	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			cin >> matriz[i][j];
		}
	}

	mostrar(filas, columnas, matriz);

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			matriz[i][j];
		}
	}

}
*/





/*bfsLoco(Grafo g, raiz s) {
	for (int i = 0; i < g.cantNodos(); ++i){
		
	}
}*/