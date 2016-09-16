#include "graph.h"

void imprimirVector(vector<int> v){
	if(v.size() == 0) return; // si no tiene nada, que no imprima nada
	for(int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << endl;
}



int main(int argc, char const *argv[])
{
	
	int cantNodos;
	int cantAristas;

	cin >> cantNodos >> cantAristas;

	Grafo g = Grafo(cantNodos);


	g.leer(cantAristas);

	//g.mostrar();

	vector<int> v;
	 cout << g.caminoMinimo(0,v)<<endl;
	 imprimirVector(v);

	return 0;
}

vector<int> reverse(vector<int> v){
	int j = 0;
	vector<int> res;
	for(int i = v.size()-1; i >= 0; --i){
		res.push_back(v[i]);
	}
	return res;
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

bool pertenece(int e, vector<int> v){
	return v[e];
}

int Grafo::buscarMin(int minimos[], vector<int> zonaSegura){
	//int max = zonaSegura[0]; 


	int min= INF;
	int res = -1;
	for (int i = 0; i < _cantnodos; ++i){
		if(!(pertenece(i,zonaSegura)) && minimos[i]<min){
			min = minimos[i];
			res = i;
		}
	}

	return res;
}


void armarCaminoaux(vector<int>& res, vector<int>& v, int indice){
	if(indice==0){	
		res.push_back(1);
	}else{ 

	res.push_back(indice+1);
	 armarCaminoaux(res, v, v[indice]);
	}
}


vector<int> armarCamino(vector<int> v){
	vector<int> res;
	int n = v.size();

	armarCaminoaux(res, v, n-1);
	return res;
}



int Grafo::caminoMinimo(int origen, vector<int>& v){
	int minimos[_cantnodos]; // Arreglo de costos, indexado por nodos.
	vector<int> predecesor (_cantnodos); // diccionario, dado un nodo devuelve su predecesor.
	vector<int> zonaSegura (_cantnodos, 0);  // ya se sabe cuanto cuesta llegar a estos nodos.
	zonaSegura[origen] = 1;
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
	for (int j = 1; j < _cantnodos; ++j){
		w = buscarMin(minimos, zonaSegura);
		if(w==-1){
			return -1;
		}
		zonaSegura[w] = 1;
		

		for (int i = 0; i < _cantnodos ; ++i){
			if(!pertenece(i,zonaSegura) && _matriz[w][i]!=0){
				if(minimos[i] > minimos[w] + _matriz[w][i]){
					minimos[i] = minimos[w] + _matriz[w][i];
					predecesor[i] = w;
				}
			}

		}

	}
	v = reverse(armarCamino(predecesor));
	return minimos[_cantnodos-1];
}




/*void Grafo::imprimirVector(int v[]){
	if(_cantnodos == 0) return; // si no tiene nada, que no imprima nada
	for(int i = 0; i < _cantnodos; ++i){
		cout << v[i] << " ";
	}
	cout << endl;
}*/



/*	for(int k = 0; k < _cantnodos; ++k){
		cout << minimos[k] << " ";
	}
	cout << endl;*/