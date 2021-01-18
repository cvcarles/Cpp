#include <cstdlib>
#include <iostream>
#include <cstring>
#include <valarray>
#include <cstdlib>

using namespace std;

valarray <valarray<int>> initMatrice(int m, int n) {
	srand(time(NULL));
	valarray <valarray<int>> v(m);
	valarray <int> v1(n);
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			v1[j]=rand()%99+1;
		}
		v[i]=v1;
	}
	return v;
}

void ecrireMatrice(valarray<valarray<int>> v) {
	for (valarray <int> x:v) {
		for (int y: x) {
			cout << y;
			if (y<10) cout << "  | ";
			else cout << " | ";
		}
		cout << endl;
		for (int i=0; i<x.size(); i++) cout << "--   ";
		cout << endl;
	}
}

int main(){
	int m, n;
	cout << "Lignes: ";
	cin >> m;
	cout << endl << "Colonnes: ";
	cin >> n;
	cout << endl << endl;
	valarray <valarray<int>> v=initMatrice(m,n);
	ecrireMatrice(v);
	return EXIT_SUCCESS;
}