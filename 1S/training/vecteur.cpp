#include <iostream>
#include <cstdlib>
#include "vecteur.hpp"

void vecteur::essai(const int a, const int b) const{
	std::cout << a << " , " << b << std::endl;
}

void vecteur::setLenght(const int l){
	this->lenght=l;
}

int vecteur::getLenght() const{
	return this->lenght;
}