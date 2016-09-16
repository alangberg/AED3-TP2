#include "graph.cpp"



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
	 if(v.size() > 0) cout<< v.size()<< endl;
	 imprimirVector(v);

	return 0;
}
