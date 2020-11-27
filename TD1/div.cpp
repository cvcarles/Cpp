#include <cstdlib>
#include <iostream>

using namespace std;

void div(int a, int b, int &q, int &r){
	while((a-b)>=0){
		a = a-b;
		q++;
	}
	r = a;
}

int main(){
	int a = 0;
	int b = 0;
	int q = 0;
	int r = 0;
	cout << "a?";
	cin >> a;
	cout << "b?";
	cin >>b;
	div(a, b, q, r);
	cout << "q = " << q << endl;
	cout << "r = " << r << endl;
	cout << a << " = " << q << "*" << b << "+" << r << endl;
}