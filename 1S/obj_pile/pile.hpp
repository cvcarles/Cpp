#pragma once
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>

template <typename T>
class Pile {
public:
	virtual ~Pile() {};

	virtual bool estVide() const =0;

	virtual void empiler(const T &x) =0;

	virtual void depiler() =0;

	virtual const T &sommet() const =0;

	virtual const std::string toString() const =0;

	friend std::ostream &operator<<(std::ostream &f, const Pile<T> &p){
		return f << p.toString();
	}
};