#include "graph.h"


Grafo::Grafo(){
	_cantnodos= 0;
	_matriz= (vector<vector<int> > ());
}

Grafo::Grafo(int cantnodos): _cantnodos(cantnodos){
   vector<int> v (cantnodos,0);

   vector<vector<int> > matriz (cantnodos,v);
    _matriz = matriz;
}

int Grafo::cantNodos(){
	return _cantnodos;
}

void Grafo::leer(int cantAristas){
	int desde, hasta, peso;

	for (int k = 0; k < cantAristas; ++k){
		cin >> desde >> hasta >> peso;

		_matriz[desde-1][hasta-1] = peso;
	}
}

void Grafo::mostrar() const{

cout<<"------------------"<<endl;
    for(int i=0;i<_cantnodos ;i++){
        cout<<"[";
        for(int j=0;j<_cantnodos;j++){
         if(j!=_cantnodos-1){
        cout<<_matriz[i][j]<<",";
        }else{
        cout<<_matriz[i][j]<<"]"<<endl;
        	}
		}


}
cout<<"------------------";
}


int Grafo::buscarMin(int minimos[], vector<bool> zonaSegura){
	//int max = zonaSegura[0]; 


	int min= INF;
	int res=0;
	while(res<_cantnodos && minimos[res]!=INF){
		res++;
	}

	for (int i = 0; i < _cantnodos; ++i){
		if(!(pertenece(i,zonaSegura)) && minimos[i]<min){
			min = minimos[i];
			res = i;
		}
	}

	return res;
}

int Grafo::caminoMinimo(int origen, vector<int>& v){
	int minimos[_cantnodos]; // Arreglo de costos, indexado por nodos.
	vector<int> predecesor (_cantnodos); // diccionario, dado un nodo devuelve su predecesor.
	vector<bool> zonaSegura (_cantnodos, 0);  // si la posicion "i" es true, el nodo i esta en la zona segura.
	zonaSegura[origen] = true;
	minimos[origen] = 0;
	predecesor[origen] = 0;

	for (int i = 1; i < _cantnodos; ++i){
		if(_matriz[origen][i] != 0){
			minimos[i] = _matriz[origen][i];
			predecesor[i] = origen;
		}else{
			minimos[i] = INF;
			predecesor[i] = INF;
		}
	}

	int w;
	//for (int j = 1; j < _cantnodos && !zonaSegura[_cantnodos-1]; ++j){
	for (int j = 1; j < _cantnodos; ++j){
		w = buscarMin(minimos, zonaSegura);
		/*if(w==-1){
			return -1;
		}*/

		zonaSegura[w] = true;
		

		for (int i = 0; i < _cantnodos ; ++i){
			if(!pertenece(i,zonaSegura) && _matriz[w][i]!=0){
				if(minimos[i] > minimos[w] + _matriz[w][i]){
					minimos[i] = minimos[w] + _matriz[w][i];
					predecesor[i] = w;
				}
			}

		}

	}
	if(minimos[_cantnodos-1] == INF) return -1;
	v = reverse(armarCamino(predecesor));

	return minimos[_cantnodos-1];
}
