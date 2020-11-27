#pragma once
#include <string>
#include <iostream>

class figure {
public:
// le destructeur (pédagogique)
	virtual ~figure() {
 		std::cout << "destructeur Figure" << std::endl;
 	}
	virtual std::string quiSuisJe() const;
	virtual double surface() const =0; //=0 veut dire que cette méthode est abstraite et cela veut dire que la classe aussi devient abstraite
	virtual double perimetre() const =0; 
};