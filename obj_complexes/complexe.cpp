#include "complexe.hpp"
#include <cmath>
#include <fstream>

double complexe::getPreelle() const {
	return this->preelle;
}

void complexe::setPreelle(const double r) {
	this->preelle = r;
}

double complexe::getPimg() const {
	return this->pimg;
}

void complexe::setPimg(const double i) {
	this->pimg = i;
}

string complexe::toString() const {
	return "(" + to_string(this->getPreelle()) + "," + to_string(getPimg()) + ")";
}

void complexe::ecrireComplexe() const{
	cout << this->toString() << endl;
}

double complexe::rho() const {
	return sqrt(this->preelle*this->preelle+this->pimg*this->pimg);
}

double complexe::theta() const{
	return atan2(this->pimg,this->preelle);
}

complexe complexe::polcomplexe(const double rho, const double theta){
	return complexe(rho*cos(theta),rho*sin(theta));
}

complexe complexe::operator+(const complexe &c) const{
	return complexe(c.preelle+this->preelle,c.pimg+this->pimg);
}

complexe complexe::operator-(const complexe &c) const{
	return complexe(this->preelle-c.preelle,this->pimg-c.pimg);
}

complexe complexe::operator*(const complexe &c) const{
	double rho=this->rho()*c.rho(), theta=this->theta()+c.theta();
	c.polcomplexe(rho,theta);
	return c;
}

complexe complexe::operator/(const complexe &c) const{
	double rho=this->rho()/c.rho(), theta=this->theta()-c.theta();
	c.polcomplexe(rho,theta);
	return c;
}

bool complexe::operator==(const complexe &c) const{
	return c.pimg==this->pimg and c.preelle==this->preelle;
}

bool complexe::operator!=(const complexe &c) const{
	return c.pimg!=this->pimg and c.preelle!=this->preelle;
}

std::ofstream &operator<< (std::ofstream &f, const complexe &c){
	f.write((char *) &c, sizeof(complexe));	
	return f;
}

std::ostream &operator<< (std::ostream &f, const complexe &c){
	return f << c.toString();
}

std::ifstream &operator>> (std::ifstream &f, complexe &c){
	f.read((char *) &c, sizeof(complexe));
	return f;
}

std::istream &operator>> (std::istream &f, complexe &c){
	double i, r;
	f>>r;
	f>>i;
	c.setPimg(i);
	c.setPreelle(r);
	return f;
}