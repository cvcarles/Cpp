#include <cstdlib>
#include <iostream>

const int ANNEE_COURANTE = 2020;
int annee_naissance, age;

int main(){
	std::cout<< "Quelle est votre date de naissance?" << std::endl;
	std::cin>>annee_naissance;
	std::cout << "votre âge : " << ANNEE_COURANTE - annee_naissance << std::endl;
	return EXIT_SUCCESS;
}