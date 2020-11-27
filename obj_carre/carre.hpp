#pragma once
#include <cstdlib>
#include <iostream>
#include "rectangle.hpp"
#include <string>
#include <cassert>

class carre: public rectangle {

typedef rectangle super;

public:
	double getLargeur() const = delete;
	double getLongueur() const = delete;

	void setLargeur(const double l) = delete;
	void setLongueur(const double L) = delete;

	carre(const double c=0) : rectangle(c,c) { }
 	carre(const rectangle &r) : rectangle(r.getLargeur(), r.getLargeur()) {
 		assert(r.getLargeur()== r.getLargeur());
 	}

 	double surface() const override;

	void setCote(const double c);

	double getCote() const;

 	virtual std::string quiSuisJe() const override;

	friend std::ostream &operator<<(std::ostream &f, const carre &r);
};