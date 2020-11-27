#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string s1="Bonjour", s2=" à tous", s3, s4;
	s3=s1+s2;
	s4=s3;
	cout << s3 << endl;
	s4[0]='Z';
	cout << s4 << endl;
	return EXIT_SUCCESS;
}