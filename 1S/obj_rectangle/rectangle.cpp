#include "rectangle.hpp"

double rectangle::getLargeur() const{
	return this->largeur;
}

double rectangle::getLongueur() const{
	return this->longueur;
}

void rectangle::setLargeur(const double l){
	this->largeur=l;
}

void rectangle::setLongueur(const double L){
	this->longueur=L;
}

double rectangle::perimetre() const{
	return (this->largeur*2)+(this->longueur*2);
}

double rectangle::surface() const{
	return this->longueur*this->largeur;
}

std::string rectangle::quiSuisJe() const {
	return "un rectangle";
}

double rectangle::operator<(const rectangle &r) const{
	return this->surface()<r.surface();
}

std::ostream &operator<<(std::ostream &f, const rectangle &r){
	std::string s;
	s = "(" + std::__cxx11::to_string(r.largeur) + "," + std::__cxx11::to_string(r.longueur) + ")";
	return f << s;
}