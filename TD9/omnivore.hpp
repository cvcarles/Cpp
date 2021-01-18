#pragma once
#include "herbivore.hpp"
#include "carnivore.hpp"

class omnivore : public carnivore, public herbivore {
    typedef animal super;
public:
    omnivore(const double kg=0) : super(kg), carnivore(kg), herbivore(kg) {}
    void jeMange() const override {
        std::cout << "Je mange " << super::getRation() << " Kg d'herbe et de viande";
    }

};