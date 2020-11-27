#pragma once
#include <cassert>
#include <string>
#include "ellipse.hpp"

class Cercle : public Ellipse {
// invariant : petitRayon, grandRayon>=0 et petitRayon=grandRayon
typedef Ellipse super;
private:
	double getPetitRayon() const;
	double getGrandRayon() const;
	void setPetitRayon(const double pa);
	void setGrandRayon(const double ga);

public:
 	Cercle(const double r=0) : Ellipse(r,r) {
 	assert(r>=0);
	}

 	Cercle(const Ellipse &e) : Ellipse(e.getPetitRayon(), e.getPetitRayon()) {
 	assert(e.getPetitRayon() == e.getPetitRayon());
 	}

	void setRayon(const double r);
	double getRayon() const;

 	virtual std::string quiSuisJe() const override;
	friend std::ostream&operator<<(std::ostream &f, const Cercle& c);
};