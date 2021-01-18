#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include <cmath>
#include "figure.hpp"

class Ellipse : public figure {
/* Invariant : petitRayon>=0, grandRayon>=0 */
protected:
	double petitRayon;
	double grandRayon;
public:
	Ellipse(const double pr=0, const double gr=0) :
		petitRayon(pr), grandRayon(gr) {
 		assert(pr>=0 && gr>=0);
 		}

#ifdef DEBUG
// le destructeur (pédagogique)
 	~Ellipse() {
 		std::cout << "destructeur Ellipse" << std::endl;
 	}
#endif

	double getPetitRayon() const;

	double getGrandRayon() const;

	void setPetitRayon(const double pa);

	void setGrandRayon(const double ga);

	double perimetre() const override;

	double surface() const override;

 	virtual std::string quiSuisJe() const override;

	friend std::ostream&operator<<(std::ostream &f, const Ellipse& e);
};