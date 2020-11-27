#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <valarray>

using namespace std;

/*
 *Rôle: renvoie le produit scalaire des vecteurs v1 et v2
 */
double produitScalaire(const valarray<double> &v1, const valarray<double> &v2) {
	double x=0;
	if (v1.size()!=v2.size()) return -1;
	for (int i=0; i<v1.size(); i++) x+=(v1[i]*v2[i]);
	return x;
}


int main(){
	valarray <double> v1={2.2, 3.1, 4.3}, v2= {2.3, 6.3, 5.4};
	double x=produitScalaire(v1,v2);

	cout << x << endl;
	
	return EXIT_SUCCESS;
}