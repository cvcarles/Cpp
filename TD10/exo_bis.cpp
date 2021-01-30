#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

class Dico {
protected:
    map<string, int> dico;
public:
    Dico() {}
    void inserer(const string mot) {
        if (dico.find(mot) == dico.end()) dico[mot] = 1;
        else dico[mot] +=1;
    }
    const std::string toString() const {
        std::ostringstream s;
        for (typename map<string, int>::const_iterator it = this->dico.begin(); it!=this->dico.end(); it++) {
            cout << it->first << ": " << it->second << endl;
        }
		return s.str();
    }
    friend std::ostream &operator<<(std::ostream &f, const Dico &d) {
        return f << d.toString();
    }
};

void lecture(string s1) {
    Dico liste;

    ifstream ios(s1); //ios designe le nom de la variable de type fichier (entree)
	if (!ios.is_open()) {
	perror(s1.c_str());
	exit (EXIT_FAILURE);
	}
    char c;
    string s= "";

    while (ios.get(c)){
        if (c!='\n') {
            if (c == ' ') {
                liste.inserer(s);
                cout << "j'ajoute " << s << endl;
                s = "";
            }
            else s+=c;
        }
	}

    cout << liste << endl;

    ios.close();
}

int main(){
    lecture("text.txt");

    return EXIT_SUCCESS;
}