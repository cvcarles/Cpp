#include <iostream>
#include <cstdlib>
#include <vector>
#include "rectangle.hpp"
#include "carre.hpp"
#include "figure.hpp"
#include "ellipse.hpp"
#include "cercle.hpp"

#include "pile.hpp"
#include "pileTableau.hpp"

using namespace std;

int main(){
	
	Pile<int> *pi = new PileTableau<int> ();

	pi.empiler(5);

	return EXIT_SUCCESS;
}