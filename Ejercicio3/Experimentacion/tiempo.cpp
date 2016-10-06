#include "../graph.cpp"
#include <chrono>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <utility>
#include <iostream>
#include <fstream>
#include <time.h>

#define ya chrono::high_resolution_clock::now
using namespace std;

template<typename S, typename T>
struct tupla{
	S primero;
	T segundo;
	tupla(S p, T s) : primero(p), segundo(s){}
};

clock_t tStart;
clock_t tFinish;

// parametros de entrada
// 1-repeticiones, 2-desde, 3-hasta, 4-incremento, 5-salida
// $ ./tiempo 100 0 33 1 data.out
int main(int argc, char const *argv[]){
	int repeticiones = atoi(argv[1]);

	int cantNodos=0;
	int cantAristas;

	vector< tupla<int , double> > mediciones;
	for (int i = 0; i < 20; ++i){
	
		cin >> cantNodos >> cantAristas;

		Grafo g = Grafo(cantNodos);


		g.leer(cantAristas);

		vector<int> v;
		int solucion;
		double medicion = 0;
		auto inicio_medicion = ya();
		for(int i = 0; i < repeticiones; i++){
			solucion = 	g.caminoMinimo(0,v);

		}	
		auto fin_medicion = ya();
		tupla<int, double> t(cantNodos, (double) chrono::duration_cast<std::chrono::nanoseconds>(fin_medicion - inicio_medicion).count()/repeticiones);
		
		if(solucion!= -1) mediciones.push_back(t);
	}
		
	for(int i = 0; i < mediciones.size(); i++){
		cout <<fixed<< mediciones[i].primero << " "
			<< mediciones[i].segundo << endl;
	}
}




