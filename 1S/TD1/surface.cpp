#include <cstdlib>
#include <iostream>

int largeur, longueur, surface;

int main(){
	using namespace std;
	
	cout << "largeur du rectangle :" << endl;
	cin>>largeur;
	cout << "longueur du rectangle :" << endl;
	cin>>longueur;
	surface = largeur * longueur;
	cout << "largeur :" << largeur << endl << "longueur :" << longueur << endl << "la surface du rectangle est :" << surface <<endl;
	return EXIT_SUCCESS;
}
