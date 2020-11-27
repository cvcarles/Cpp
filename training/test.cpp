#include <iostream>
#include <cstdlib>
#include "vecteur.hpp"
#include <fstream>
#define ANNEE_COURANTE 2020

using namespace std;

void echanger (int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

int main(){

	vecteur v;
	v.setLenght(4);

	cout << v.getLenght() << endl;
	v.essai(3,4);

	ofstream oos("Salut");
	if (!oos.is_open()) {
		perror("Salut");
		exit(EXIT_FAILURE);
	}
	string s1="BLAblaght";
	oos.write(s1,sizeof(string));

	oos.close();

	return EXIT_SUCCESS;
}