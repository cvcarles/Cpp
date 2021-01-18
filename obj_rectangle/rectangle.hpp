#pragma once
#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class rectangle : public figure {
protected:
	double largeur;
	double longueur;
public:
	rectangle(const double l=0, const double L=0): largeur(l), longueur(L) {}

	double getLargeur() const;
	double getLongueur() const;

	void setLargeur(const double l);
	void setLongueur(const double L);

	double perimetre() const;
	double surface() const;

	virtual std::string quiSuisJe() const;

	double operator<(const rectangle &r) const;

	friend std::ostream &operator<<(std::ostream &f, const rectangle &r);
};