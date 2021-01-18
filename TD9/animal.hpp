#pragma once


class animal {
protected:
    double ration;
public:
    animal(double r) : ration(r) {
        std::cout << "J'ai construit un animal" << std::endl;
    }

    double getRation() const {
        return this->ration;
    }

    virtual void jeMange() const = 0;

};