#pragma once
#include <string>

class salarie {
protected:
    std::string nom;
    double salaire;
public:
    salarie(std::string e, double s) : nom(e), salaire(s) {}

    std::string getNom() {
        return this->nom;
    }

    double getSalaire() {
        return this->salaire;
    }

};