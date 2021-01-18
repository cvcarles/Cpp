#pragma once
#include <string>
#include "animal.hpp"

class herbivore : public virtual animal {
    typedef animal super;
public:
    herbivore(double r) : super(r) {}
    void jeMange() const override {
        std::cout << "Je mange " << super::getRation() << " Kg d'herbe";
    }

};