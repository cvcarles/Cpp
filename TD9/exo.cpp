#include <cstdlib>
#include <iostream>
#include "enseignant.hpp"
#include "omnivore.hpp"

using namespace std;

int main(){
    
    enseignant prof("SonNom", 35, "Polytech", 100, "Electronique");

    cout << prof.personne::getNom() << endl;
    cout << prof.salarie::getNom() << endl;

    omnivore kangourou;
    kangourou.jeMange();
    cout << endl;

    cout << kangourou.getRation() << endl;

    animal *faune[] = {new omnivore(10), new herbivore (60), new carnivore(7)};

    for (animal *a : faune){
        a->jeMange();
        cout << endl;
    }

    return EXIT_SUCCESS;
}