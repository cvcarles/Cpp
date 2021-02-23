#include <cstdlib>
#include <iostream>
#include <iterator>
#include "matrice.hpp"
#include "commandes.hpp"

using namespace std;

int main() {
    const int M = 3;
    const int N = 4;

    Matrice<M,N,int> m;
    char code;
    Command *cmd = nullptr;
    bool undoing_mode = false;

    srand(time(nullptr));

    cout << m << "----------------------------" << endl;
    cout << "cmd>";

    while (cin >> code) {
        if (code == 's' || code == 'a' || code == 'q') {
            switch (code) {
                case 's' : cmd = new SetValue<M,N,int>(&m, random()%M, random()%N, random()%100); break;
                case 'a' : cmd = new AddValue<M,N,int>(&m, random()%100); break;
                case 'q' : return EXIT_SUCCESS;
                default : cerr << "Commande inconnue" << endl;
            }
            cmd->execute();
            undoing_mode = false;
        }
        else {
            if (code == 'u') {
                if (cmd != nullptr) {
                    if (undoing_mode) {
                        cmd->execute();
                        undoing_mode = false;
                    }
                    else {
                        cmd->undo();
                        undoing_mode = true;
                    }
                }
            }
            else {
                cerr << "Commande inconuue" << endl;
            }
        }
        cout << m << "----------------------------" << endl;
        cout << "cmd>";
    }
    return EXIT_SUCCESS;
}