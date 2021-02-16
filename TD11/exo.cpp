#include <cstdlib>
#include <iostream>
#include <iterator>
#include "matrice.hpp"

using namespace std;

int main() {
    const int M = 3;
    const int N = 4;

    Matrice<M,N,int> m;
    char code;

    cout << m << "----------------------------" << endl;
    cout << "cmd>";

    while (cin >> code) {
        int v;
        switch (code) {
            case 's' : m(random()%M, random()%N) = random()%100; break;
            case 'a' : v = random()%100; for (auto it = m.begin(); it != m.end(); it++) *it+=v; break;
            default : cerr << "Commande inconnue" << endl;
        }
        cout << m << "----------------------------" << endl;
        cout << "cmd>";
    }
    return EXIT_SUCCESS;
}