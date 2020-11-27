#include <cstdlib>
#include <iostream>

int max(int a, int b){
	if(a<b) return b;
	else return a;
}

int max(int a, int b, int c){
	if(a>b && a>c) return a;
	else if(b>a && b>c) return b;
	else return c;
}

double max(double a, double b){
	return a>b ? a : b;
}

int main(){
	using namespace std;
	cout << "max1 = " << max(3.33, 10.45) << " max2 = " << max(1, 10, 100) << endl;
	return EXIT_SUCCESS;
}