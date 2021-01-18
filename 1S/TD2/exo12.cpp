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

int main(){
	vector <string> v1, v2;
	v1 = {"a", "b", "c"};
	v2=v1;
	v2[0]="d";
	afficherVecteur(v1);
	afficherVecteur(v2);

	return EXIT_SUCCESS;
}