#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <cassert>

using namespace std;

class RLE_Exception : public exception{
protected:
    string msg;
public:
    RLE_Exception(string m, string av, string ap) {
        this->msg = m + ", " + av + " [" + ap + "]";
    }

    RLE_Exception(const RLE_Exception &e) : msg(e.msg) {}
    virtual const char *what() const noexcept override {
        return this->msg.c_str();
    }
};

class rle {
private:
    const int lg_max = 9;
    char marqueur;
public:
    rle (const char c) : marqueur(c) {}
    string comprimer (const string &s) const {
        int longueur = s.size();
        int i=0;
        string result;
        while (i < longueur) {
            if (s[i] == this->marqueur) {
                result.push_back(this->marqueur);
                result.push_back('0');
                i+=1;
            }
            else {
                int k=0;
                while (s[i+k+1] == s[i+k]) k+=1;
                result.push_back(s[i]);
                result.push_back(this->marqueur);
                result+=to_string(k+1);
                i+=k+1;
            }
        }
        return result;
    }
    string decomprimer (const string &s) const {
        int longueur = s.size();
        int i=0;
        string result;
        while (i < longueur) {
            if (s[i] == this->marqueur) {
                if (s[i+1]-'0' != 0) throw RLE_Exception("0 attendu", s.substr(0,i+1), s.substr(i+1));
                result.push_back(this->marqueur);
                i+=2;
            }
            else {
                if (s[i+1] != this->marqueur) throw RLE_Exception("Marqueur attendu", s.substr(0,i+1), s.substr(i+1));
                else if (s[i+2]-'0' < 1 || s[i+2]-'0' > this->lg_max) throw RLE_Exception("Mauvais indice", s.substr(0,i+1), s.substr(i+1));
                for (int k=0; k < s[i+2]-'0' ; k++) result.push_back(s[i]);
                i+=3;
            }
        }
        return result;
    }
};



template<typename T>
class intervalle {
private:
    T binf;
    T bsup;
    intervalle<T> *suivant;
public:
    intervalle (const T &inf, const T &sup, intervalle<T> *n = nullptr) : binf(inf), bsup(sup), suivant(n) { assert(inf <= sup); }
    const T &getbinf() const {
        return this->binf;
    }
    const T &getbsup() {
        return this->bsup;
    }
    intervalle<T> *getsuivant() const {
        return this->suivant;
    }
};
template<typename T>
class singleton : public intervalle<T> {
private:
    T borne;
    intervalle<T> *suivant = nullptr;
public:
    singleton(const T &b) : intervalle<T>(b,b) {}
};

template<typename T>
class hlm {
private:
    intervalle<T> *tete;
public:
    hlm<T>() : tete(nullptr) {}
    bool vide() {
        return this->tete == nullptr;
    }
    bool appartient(const T &x) {
        intervalle<T> *i = tete;
        while (i != nullptr) {
            if (x >= i->getbinf() && x <= i->getbsup()) return true;
            i = i->getsuivant();
        }
        return false;
    }
};

void finir(){
    cerr << "Nouveau message d'arrêt" << endl;
}

int main(){
    std::set_terminate(finir);
    rle c('#');
    string s ="c#5#0h#6";
    string s1 = "cccc##hh#666";
    try {
        cout << c.decomprimer(s) << endl;
    }
    catch (const RLE_Exception &e) {
        cerr << e.what () << endl ;
    }
    //cout << c.decomprimer(s) << endl;
    cout << c.comprimer(s1) << endl;

    return EXIT_SUCCESS;
}