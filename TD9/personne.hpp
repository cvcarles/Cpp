#pragma once
#include <string>

class personne {
protected:
    std::string nom;
    int age;
public:
    personne(std::string n, int a) : nom(n), age(a) {}

    std::string getNom() {
        return this->nom;
    }

    int getAge() {
        return this->age;
    }
};