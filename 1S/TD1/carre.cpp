#include <cstdlib>
#include <iostream>

#define CARRE(x) ((x) * (x))

using namespace std;

inline int carre(int x){
	return x*x;
}

int main(){
	int a = 3;
	cout << CARRE(a++) << endl;
	a = 3;
	cout << carre(a++) << endl;
	return EXIT_SUCCESS;
}