#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

vector <vector<int>> initMatrice(int m, int n) {
	srand(time(NULL));
	vector <vector<int>> v;
	vector <int> v1;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			v1.push_back(rand()%99+1);
		}
		v.push_back(v1);
		v1.clear();
	}
	return v;
}

void ecrireMatrice(vector<vector<int>> v) {
	for (vector <int> x:v) {
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
	int m=10, n=5;
	vector <vector<int>> v=initMatrice(m,n);
	ecrireMatrice(v);
	return EXIT_SUCCESS;
}