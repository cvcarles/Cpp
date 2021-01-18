#include <cstdlib>
#include <iostream>
#include <fstream>
#include "complexe.hpp"

using namespace std;

void copier(const string &s1, const string &s2){
	ifstream ios(s1); //ios designe le nom de la variable de type fichier (entree)
	if (!ios.is_open()) {
	perror(s1.c_str());
	exit (EXIT_FAILURE);
	}

	ofstream oos(s2); //oos designe le nom de la variable de type fichier (sortie)
	char c;
	while (ios.get(c)) oos.put(c);
	ios.close(); oos.close();
}

void copierBuff(const string &s1, const string &s2){
	ifstream ios(s1); //ios designe le nom de la variable de type fichier (entree)
	if (!ios.is_open()) {
	perror(s1.c_str());
	exit (EXIT_FAILURE);
	}

	ofstream oos(s2); //oos designe le nom de la variable de type fichier (sortie)
	if (!oos.is_open()) {
	perror(s2.c_str());
	exit (EXIT_FAILURE);
	}

	while (!ios.eof()){
		char buf[BUFSIZ];
		ios.read(buf,BUFSIZ);
		oos.write(buf, ios.gcount());
		}
	ios.close(); oos.close();
}

void exo5() {
	int n;

	ofstream oos1("fc"); //oos designe le nom de la variable de type fichier (sortie)
	if (!oos1.is_open()) {
	perror("fc");
	exit (EXIT_FAILURE);
	}

	cout << "Nombre de complexes à écrire: ";
	cin >> n;

	for (int i=0; i<n; i++) {
		int pimg=0, preelle=0;
		cout << "pr: ";
		cin >> pimg;
		cout << "pi: ";
		cin >> preelle;
		complexe c(pimg,preelle);
		oos1.write((char *) &c, sizeof(complexe));
	}

	oos1.close();

	ifstream ios("fc"); //ios designe le nom de la variable de type fichier (entrée)
	if (!ios.is_open()) {
	perror("fc");
	exit (EXIT_FAILURE);
	}

	ofstream oos2("Complexes sortie"); //oos designe le nom de la variable de type fichier (sortie)
	if (!oos2.is_open()) {
	perror("Complexes sortie");
	exit (EXIT_FAILURE);
	}

	while (!ios.eof()){
		complexe c;
		ios.read((char *) &c,sizeof(complexe));
		oos2.write((char *) &c, ios.gcount());
		}
	ios.close(); oos2.close();
}

void exo6() { //ecrit un complexe de trop
	ifstream ios("fc"); //ios designe le nom de la variable de type fichier (entrée)
	if (!ios.is_open()) {
	perror("fc");
	exit (EXIT_FAILURE);
	}

	complexe c;
	ios >> c;
	cout << c << endl;;

	ios.close();
}

int main(){
	/*string c1,c2;

	cout << "Fichier d'entrée: ";
	cin >> c1;
	cout << "Fichier de sortie: ",
	cin >> c2;
	copierBuff(c1,c2);*/

	/*ofstream oos("fc");
	oos << complexe(1,2);
	oos.close();*/

	exo5();
	exo6();

	/*int n;
	cin >> n;
	cout << hex << n << endl;
	cout << oct << n << endl;
	cout << dec << n << endl;*/

	return EXIT_SUCCESS ;
}