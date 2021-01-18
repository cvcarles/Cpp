#include <cstdlib>
#include <iostream>


void echanger(int &a, int &b){
	int x=a;
	a = b;
	b = x;
}

int main(){
	using namespace std;
	int a = 5;
	int b = 8;
	cout << "le 1er paramètre est : " << a <<" et le 2e est : " << b << endl;
	echanger(a, b);
	cout << "maintenant, le 1er paramètre est : " << a <<" et le 2e est : " << b << endl;
	return EXIT_SUCCESS;
}