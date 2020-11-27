#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string s1="Bonjour", s2=" à tous", s3;
	s3=s1+s2;
	printf("%s\n",s3.c_str());
	return EXIT_SUCCESS;
}