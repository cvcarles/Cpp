#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

void printStr(string c) {
	for (string x:c) {
		cout << x;
	}
	cout << "." << endl;
}

int main(){
	string c="Coucou";
	printStr(c);
}