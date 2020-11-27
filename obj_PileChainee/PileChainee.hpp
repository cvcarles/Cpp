#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "noeud.hpp"

template <typename T>

class PileChainee {
private:
	noeud<T> *sp; //Sommet de la pile

public:
	PileChainee() : sp(nullptr) {} //constructeur

	PileChainee(const PileChainee<T> &p) {
		this->sp = dupliquer(p.sp);
	} //constructeur de copie

	~PileChainee() {
		this->detruire(this->sp);	
	} //destructeur

	bool estVide() const{
		return this->sp==nullptr;
	}

	void empiler(const T x){
		noeud<T> *p = new noeud<T>(x, this->sp);
		this->sp = p;
	}

	void depiler(){
		noeud<T> *p = (this->sp)->getSuivant();
		delete this->sp;
		this->sp=p;
	}

	T sommet() const{
		assert(!this->estVide());
		return (this->sp)->getElement();
	}

	noeud<T> *dupliquer(noeud<T> *s){
		if (s==nullptr) return nullptr;
		noeud<T> *p ,*q;
		p = q = new noeud<T>(s->getElement());
		while (s->getSuivant() != nullptr) {
			s = s->getSuivant();
			q->setSuivant(new noeud<T>(s->getElement()));
			q = q->getSuivant();
		}
		return p;
	}

	void detruire(noeud<T> *n){
		while (n!=nullptr) {
			noeud<T> *p = n->getSuivant();
			delete n;
			n = p;
		}
	}

	const std::string toString() const{
		std::ostringstream s;
		s << "[ ";
		noeud<T> *n = this->sp;
		while (n!=nullptr) {
			s << n->getElement() << " ";
			n = n->getSuivant();
		}
		s << "]";
		return s.str();
	}

	friend std::ostream &operator<< (std::ostream &f, const PileChainee<T> &p){
		return f << p.toString();
	}

	PileChainee<T> &operator=(const PileChainee<T> &p){
		this->sp = dupliquer(p.sp);
		return *this;
	}
};