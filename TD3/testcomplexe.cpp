#include <cstdlib>
#include <iostream>
#include "complexe.hpp"

using namespace std;

int main(void) {
	complexe c1;
	complexe c2(4.5);
	complexe c3(-1, 0);

	c3.ecrireComplexe();
	cout << c3.rho() << " , " << c3.theta() << endl;
	complexe::polcomplexe(c3.rho(),c3.theta()).ecrireComplexe();

	return EXIT_SUCCESS;
}