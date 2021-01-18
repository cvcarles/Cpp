#include "ellipse.hpp"
#include <cmath>

double Ellipse::getPetitRayon() const {
	return this->petitRayon;
}

double Ellipse::getGrandRayon() const {
	return this->grandRayon;
}

void Ellipse::setPetitRayon(const double pa) {
	this->petitRayon = pa;
}
void Ellipse::setGrandRayon(const double ga) {
	this->grandRayon = ga;
}

double Ellipse::perimetre() const {
	return M_PI*sqrt(2*((this->petitRayon*this->petitRayon)+(this->grandRayon*this->grandRayon)));
}
double Ellipse::surface() const {
	return M_PI * this->petitRayon * this->grandRayon;
}

std::ostream&operator<<(std::ostream &f, const Ellipse& e) {
	return f << "ellipse(" << e.petitRayon << "," << e.grandRayon << ")";
}

std::string Ellipse::quiSuisJe() const {
	return "une ellipse";
}