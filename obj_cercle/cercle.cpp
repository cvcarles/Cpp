#include "cercle.hpp"

void Cercle::setRayon(const double r) {
 	super::setPetitRayon(r);
 	super::setGrandRayon(r);
}
double Cercle::getRayon() const {
	return super::getPetitRayon();
}

std::ostream&operator<<(std::ostream &f, const Cercle& c) {
	return f << "cercle(" << c.getRayon() << ")";
}

std::string Cercle::quiSuisJe() const {
	return "un cercle";
}