#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string s1="Bonjour", s2=" à tous", s3;
	s3=s1+s2;
	cout << s3 << endl;
	cout << s3.find('o') << endl;
	return EXIT_SUCCESS;
}