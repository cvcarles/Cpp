#include <cstdlib>
#include <iostream>

class vecteur{
private:
	int lenght;
public:
	vecteur (const int l=0) : lenght(l) {}
	vecteur(const vecteur &v) {
		
	}
	~vecteur() {
		std::cout << "Tout cassé le vecteur" << std::endl;
	}

	void essai(const int a, const int b) const;

	void setLenght(const int l);

	int getLenght() const;

};