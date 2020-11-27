#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
	char16_t c1=L'a';
	char32_t c2=L'a';
	wchar_t c3=L'\u0190'; //Point d'interrogation à la place du charactère attendu
	wchar_t c4=L'\u0077';
	wchar_t c5=L'\u00c2'; //Point d'interrogation à la place du charactère attendu
	cout << c1 << c2 << endl;
	wcout << c3 << c4 << endl;
	wcout << c5 << endl;
	return EXIT_SUCCESS;
}