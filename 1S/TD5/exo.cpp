#include "complexe.hpp"
#include "PileChainee.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	/*complexe *pc0 = new complexe(3.1, 6.56);
	
	int *pi = new int[10];
	complexe *pc = new complexe[5];
	complexe **ptpc = new complexe*[10];

	pi[1]=10;

	cout << "pi[1]= " << pi[1] << endl;
	cout << "pi[11]= " << pi[11] << endl;
	cout << "pc[2]= " << pc[2] << endl;
	cout << "ptpc[2]= " << ptpc[2] << endl;

	delete pc0;
	delete [] pc;
	delete [] ptpc;*/

	PileChainee<int> p = PileChainee<int>();
	PileChainee<int> p1 = PileChainee<int>();
	//cout << p.estVide() << endl;
	p.empiler(6);
	p.empiler(15);
	p.empiler(-3);
	/*cout << p.sommet() << endl;
	cout << p.estVide() << endl;
	cout << p.sommet() << endl;*/
	p1=p;
	p.depiler();
	cout << p << endl;
	cout << p1 << endl;

	return EXIT_SUCCESS;

}