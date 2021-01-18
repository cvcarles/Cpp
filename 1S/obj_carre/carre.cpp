#include "carre.hpp"

void carre::setCote(const double c) {
 	super::setLargeur(c);
	super::setLongueur(c);
}

double carre::getCote() const{
	return super::getLargeur();
}

double carre::surface() const{
	return super::surface();
}

std::string carre::quiSuisJe() const {
	return "un carre";
}

std::ostream &operator<<(std::ostream &f, const carre &c){
	return f << "carre(" << c.getCote() << ")"; 
}