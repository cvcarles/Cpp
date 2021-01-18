#include <iostream>
#include <cstdlib>
#include "rectangle.hpp"
#include "pileTableau.hpp"

using namespace std;

template <typename T>
const T& minimum(const T& x, const T& y){
	return x < y ? x : y;
}

int main(){
	rectangle r1(2,3.1), r2(12.1,0.43);
	PileTableau<rectangle> T;

	T.empiler(r1);
	T.empiler(r2);

	cout << T << endl;

	cout << minimum(r1,r2) << endl;

	return EXIT_SUCCESS;
}