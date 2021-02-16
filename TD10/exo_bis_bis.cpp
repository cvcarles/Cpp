#include <cstdlib>
#include <iostream>
#include <iterator>
#include "Matrice.hpp"

using namespace std;

int main(){
    const int M=2;
    const int N=2;
    Matrice<M,N,int> m;

    m(0,0) = 1; m(0,1) = 2;
    m(1,0) = 3; m(1,1) = 4;
    cout << "--> " << m(1,1) << endl;
    cout << "---------------------------" << endl;
    Matrice<M,N,int>::iterator it1 = m.begin();
    Matrice<M,N,int>::iterator it2(it1);
    it1++;
    cout << "*it1 = " << *it1 << " " << endl;
    cout << "*it2 = " << *it2 << " " << endl;
    cout << "*it2 = " << *it2++ << " " << endl;
    cout << "----------------------------------" << endl;
    cout << "*it2 = " << *it2 << " " << endl;
    cout << "----------------------------------" << endl;

    for (Matrice<M,N,int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << m << endl;

    return EXIT_SUCCESS;
}