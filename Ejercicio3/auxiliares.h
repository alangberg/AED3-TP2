#include <vector>
#include <iostream>
using namespace std;


void imprimirVector(vector<int> v){
	if(v.size() == 0) return; // si no tiene nada, que no imprima nada
	for(int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> reverse(vector<int> v){
	int j = 0;
	vector<int> res;
	for(int i = v.size()-1; i >= 0; --i){
		res.push_back(v[i]);
	}
	return res;
}

bool pertenece(int e, vector<bool> v){
	return v[e];
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