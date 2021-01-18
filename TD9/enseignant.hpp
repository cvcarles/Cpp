#pragma once
#include "personne.hpp"
#include "salarie.hpp"

class enseignant : public personne, public salarie {
protected:
    std::string specialite;
public:
    enseignant(std::string n, int a, std::string e, double s, std::string spe) : personne(n, a), salarie(e ,s), specialite(spe) {}

};