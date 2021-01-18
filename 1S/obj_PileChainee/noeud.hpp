#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
template <typename T>

class noeud {
private:
	T elt;
	noeud<T> *suivant;

public:
	noeud(const T &e, noeud<T> *const s=nullptr) : elt(e), suivant(s) {} //constructeur
	~noeud() {
		std::cout << "destructeur de: " << this->elt << std::endl;
	} //destructeur

	T getElement() const{
		return this->elt;
	}

	noeud<T> *getSuivant() const{
		return this->suivant;
	}

	void setElement(const T x){
		this->elt=x;
	}

	void setSuivant(noeud<T> * const s){
		this->suivant=s;
	}
};