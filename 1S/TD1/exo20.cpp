#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	double t[] = {3.1, 5.2, 6.3};
	for (double x: t) {
		cout << x << endl;
	}
}