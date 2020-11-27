#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class complexe {
private:
	double preelle;
	double pimg;

public:
	complexe(const double r = 0.0, const double i = 0.0) : preelle(r), pimg(i) {} //constructeur
	~complexe() {} //destructeur

	double getPreelle() const; //le "const" dit que l'objet courant ne sera pas modifié.
								//Quand on ajoute le const la fonction ne modifira pas l'objet courant
	void setPreelle(const double x);

	double getPimg() const;

	void setPimg(const double x);

	string toString() const;

	void ecrireComplexe() const;

	double rho() const;

	double theta() const;

	static complexe polcomplexe(const double rho, const double theta);

	complexe operator+(const complexe &c) const;

	complexe operator-(const complexe &c) const;

	complexe operator*(const complexe &c) const;

	complexe operator/(const complexe &c) const;

	bool operator==(const complexe &c) const;

	bool operator!=(const complexe &c) const;

	friend std::ofstream &operator<< (std::ofstream &f, const complexe &c);
	friend std::ostream &operator<< (std::ostream &f, const complexe &c);

	friend std::ifstream &operator>> (std::ifstream &f, complexe &c);
	friend std::istream &operator>> (std::istream &f, complexe &c);	
};