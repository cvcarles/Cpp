#pragma once
#include <string>

class carnivore : public virtual animal {
    typedef animal super;
public:
    carnivore(double r) : super(r) {}
    void jeMange() const override {
        std::cout << "Je mange " << super::getRation() << " Kg de viande";
    }

};