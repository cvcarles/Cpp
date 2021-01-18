#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void afficherVecteur(vector <auto> v) {
	for (auto c:v) {
		cout << c << ", ";
	}
	cout << endl;
}

void vecteurPair(vector <int> &v, int n) {
	int x=0;
	v.push_back(x);
	while (v.size()<n) {
		v.push_back(x+=2);
	}
}

void vecteurPairImpair(vector <int> &v) {
	int x=0, n=v.size()*2;
	for (int i=0; i<n; i++) {
		if (i%2!=0) v.insert(v.begin()+i,i);
	}
}

int main(){
	vector <int> v;
	int n;
	cin >> n;
	vecteurPair(v,n);
	vecteurPairImpair(v);
	afficherVecteur(v);

	return EXIT_SUCCESS;
}