#pragma once
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "pile.hpp"

template <typename T>
class PileTableau : public Pile {
private:
	int sp;
	int max;
	T *lesElements;

public:
	PileTableau(const int n=100): sp(0), max(n), lesElements(new T[n]) {}

	PileTableau(const PileTableau<T> &p){
		this->lesElements = new T[this->max = p.max];
		this->dupliquer(p);
	}

	~PileTableau() {
		delete [] this->lesElements;
	}

	void dupliquer(const PileTableau<T> &p){
		assert(this->max == p.max);
		for (int i=0; i<p.sp; i++)this->lesElements[i] = p.lesElements[i];
		this->sp=p.sp;
	}

	virtual bool estVide() const override{
		return this->sp==0;
	}

	virtual void empiler(const T &x) override{
		assert(this->sp < this->max);
		this->lesElements[this->sp++]=x;
	}

	virtual void depiler() override{
		assert(!this->estVide());
		this->sp--;
	}

	virtual const T &sommet() const override{
		assert(!this->estVide());
		return this->lesElements[this->sp-1];
	}

	PileTableau &operator=(const PileTableau<T> &p){
		this->dupliquer(p);
	}

	virtual const std::string toString() const override{
		std::ostringstream s;
		s << "[ ";
		for (int i=this->sp-1; i>=0; i--) s << this->lesElements[i] << ", ";
		s << "]";
		return s.str();
	}
};