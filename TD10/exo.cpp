#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <sstream>
#include <map>

template <typename T>
class Pile {
protected:
    std::forward_list<T> lf;
public:
    Pile<T>() {}
    Pile<T>(const std::forward_list<T> &l) {
        this->lf=l;
    }
    void empiler(T x) {
        this->lf.push_front(x);
    }

    void depiler() {
        this->lf.pop_front();
    }

    const T sommet() {
        typename std::forward_list<T>::const_iterator it = this->lf.end()-1;
        return *it;
    }

    bool estVide() {
        return this->lf.empty();
    }

    const std::string toString() const {
        std::ostringstream s;
		s << "<";
        for (typename std::forward_list<T>::const_iterator it = this->lf.begin(); it!=this->lf.end(); it++) s << *it << ", ";
        s << ">";
		return s.str();
    }
    friend std::ostream &operator<<(std::ostream &f, const Pile<T> &p) {
        return f << p.toString();
    }
};

void descente_reverse(const std::vector<int> &v){ // & --> Gros objet qu'on passe donc autant transmettre une adresse
    std::vector<int>::const_reverse_iterator it_v;
    std::cout << "Descente : [";
    for (it_v = v.rbegin(); it_v != v.rend(); it_v++) {
        std::cout << *it_v << ", ";
    }
    std::cout << "]" << std::endl;
}

void descente(const std::vector<int> &v){ // & --> Gros objet qu'on passe donc autant transmettre une adresse
    std::vector<int>::const_iterator it_v;
    std::cout << "Descente : [";
    for (it_v = v.end()-1; it_v >= v.begin(); it_v--) {
        std::cout << *it_v << ", ";
    }
    std::cout << "]" << std::endl;
}

void montee(const std::vector<int> &v){ // & --> Gros objet qu'on passe donc autant transmettre une adresse
    std::vector<int>::const_iterator it_v;
    std::cout << "Montée : [";
    for (it_v = v.begin(); it_v != v.end(); it_v++) {
        std::cout << *it_v << ", ";
    }
    std::cout << "]" << std::endl;
}

template <typename T> void print(std::list<T> l){
    std::cout << "<";
    for(std::list<int>::const_iterator it = l.begin(); it!=l.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << ">" << std::endl;
}

int main(){
    std::vector<int>::iterator it_v;
    std::vector<int> v = {2, 4, 6, 8, 10};

    it_v = v.begin()+1;
    *it_v=0;

    descente_reverse(v);

    v.insert(v.begin()+1, 6, -1);
    montee(v);
    v.erase(v.begin()+2, v.begin()+4);
    montee(v);

    std::forward_list<int> lf;
    std::list<int> l;

    l.push_front(4);
    l.push_front(9);
    l.push_back(0);
    std::list<int>::iterator it = l.begin();
    l.insert(++it, -1);
    l.pop_back();
    l.erase(l.begin(), it);
    l.insert(l.end(),-2);
    print(l);

    lf.push_front(1);
    lf.push_front(2);
    lf.push_front(4);
    Pile<int> p(lf);
    std::cout << p << std::endl;

    return EXIT_SUCCESS;
}