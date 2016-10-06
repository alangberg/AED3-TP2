#include <iostream>
#include <cstdlib>

using namespace std;

char dameElemento(int proba_punto, int proba_numero, int proba_numeral){
	int r = rand() % 100 + 1;
	if(r <= proba_punto) return '.';
	if(proba_punto < r && r <= proba_punto+proba_numero) return rand()%9+1 + '0';
	return '#';
}

int main(int argc, char const *argv[]){
	
	srand(time(NULL));

	int proba_punto, proba_numero, proba_numeral;
	cin >> proba_punto >> proba_numero >> proba_numeral;
	
	int F = atoi(argv[1]);
	int C = atoi(argv[2]);

	cout << F << " " << C << endl;

	for(int i = 0; i < C; ++i)
		cout << '#';
	cout << endl;

	for(int i = 0; i < F-2; ++i){
		cout << '#';
		for(int j = 0; j < C-2; ++j){
			cout << dameElemento(proba_punto, proba_numero, proba_numeral);
		}
		cout << '#' << endl;
	}

	for(int i = 0; i < C; ++i)
		cout << '#';
	cout << endl;

	return 0;
}