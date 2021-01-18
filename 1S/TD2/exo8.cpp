#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void afficherVecteurFor(vector <auto> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
}

void afficherVecteurForeach(vector <auto> v) {
	for (auto c:v) {
		cout << c << endl;
	}
}

int main(){
	vector <int> v1;
	vector <string> v2;
	vector <vector<double>> v3;
	vector <int> v4 = vector <int> (10);
	vector <string> v5 = {"ab", "ef", "azy"};

	int x1, x2, x3, x4, x5;
	x1=v1.size();
	x2=v2.size();
	x3=v3.size();
	x4=v4.size();
	x5=v5.size();

	cout << "Taille de v1: " << x1 << endl;
	cout << "Taille de v2: " << x2 << endl;
	cout << "Taille de v3: " << x3 << endl;
	cout << "Taille de v4: " << x4 << endl;
	cout << "Taille de v5: " << x5 << endl;

	//cout << "v5: " << v5 << endl; probleme de type pour v5

	afficherVecteurFor(v5);
	afficherVecteurForeach(v5);

	return EXIT_SUCCESS;
}