#include <cstdlib>
#include <iostream>

using namespace std;
void p(int x = 7, double y = 12.1, char z = 'z'){
	cout << "x = " << x << " y = " << y << "; z = " << z << endl;
}

int main(){
	p(9, 1.0, 'a');
	p(3, 'a');
	p(5, 2.3);
	p(19);
	p();
}