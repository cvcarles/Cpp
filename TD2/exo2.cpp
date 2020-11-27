#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string s1="Bonjour", s2=" à tous", s3;
	s3=s1+s2;
	//s3=strcat(s1,s2); Probleme de type en argument
	cout << s3 << endl;
	return EXIT_SUCCESS;
}