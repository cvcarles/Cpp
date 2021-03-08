#include <cstdlib>
#include <iostream>
#include <iterator>
#include "matrice.hpp"
#include "commandes.hpp"
#include "historique.hpp"

using namespace std;

int main() {
    const int M = 3;
    const int N = 4;

    Matrice<M,N,int> m;
    char code;
    Command *cmd = nullptr;
    History<Command *> *history = new HistoryList<Command *>();

    srand(time(nullptr));

    cout << m << "----------------------------" << endl;
    cout << "cmd>";

    while (cin >> code) {
        if (code == 's' || code == 'a' || code == 'q' || code == 'p' || code == 'h') {
            switch (code) {
                case 's' : cmd = new SetValue<M,N,int>(&m, random()%M, random()%N, random()%100); break;
                case 'a' : cmd = new AddValue<M,N,int>(&m, random()%100); break;
                case 'p' : cmd = new display<M,N,int>(&m); break;
                case 'h' : cmd = new help; break;
                case 'q' : return EXIT_SUCCESS;
                default : cerr << "Commande inconnue" << endl;
            }
            if (!history->is_last()) history->remove_all_right();
            history->put(cmd);
            cmd->execute();
        }
        else {
            if (code == 'u') {
                if (history->on_item()) {
                    history->item()->undo();
                    history->back();
                }
                else cerr << "Rien à défaire" << endl;
            }
            else if (code == 'r') {
                if (!history->is_last()) {
                    history->forth();
                    history->item()->redo();
                }
                else {
                    cerr << "Rien à refaire" << endl;
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