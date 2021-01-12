#include <iostream>
#include <cstdlib>

#include "MonException1.hpp"
#include "MonException2.hpp"
#include "tableau.hpp"
#include "complexe.hpp"
#include "IndexException.hpp"

using namespace std;

class MonException {
    friend std::ostream &operator<< (std::ostream &f, const MonException &c){
	    return f << "monException_from_class";
    }
};

void p(){
    switch(rand()%4){
        case 0: throw 66;
        case 1: throw MonException();
        case 2: throw "bad";
        case 3: ;
    }
    cout << "Fin de la procédure" << endl; 
}

void f(){
    throw MonException();
}

void g(){
    //f();
    try{
        f();
    }
    catch(const MonException &e){
        cerr << "Exception attrapée dans g ! : " << e << endl;
        throw ;
    }
}

void finir(){
    cerr << "Mauvais type d'exception" << endl;
}

void fprime(){
    throw MonException1();
}

void gprime(){
    throw MonException2();
}

int main(){
    std::set_terminate(finir);
	srand(time(nullptr));
    try {
        p();
    }
	catch (int e){
        cerr << "Exception de type int: " << e << endl;
    }
    catch (const MonException &e){
        cerr << "Exception de type MonException: " << e << endl;
    }
    catch (const char *e){
        cerr << "Exception de type string: " << e << endl;
    }
    catch (...){
        cerr << "Exception de type ???" << endl;
    }
    try{
        g();
    }
    catch(const MonException &e){
        cerr << "Exception attrapée dans le main ! : " << e << endl;
    }
    
    try{
        fprime();
        gprime();
    }
    catch(const MonException2 &e){
        cerr << e.what() << endl;
    }
    catch(const MonException1 &e){
        cerr << e.what() << endl;
    }

    tableau <5, complexe> tc;

    cout << tc.longueur() << endl;
    tc[0] = complexe(1,3);
    cout << tc[0] << endl;
    cout << tc << endl;

    tableau<10, int> ti1, ti2;

    ti1[5]=10;
    cout << ti1[5] << endl;

    ti2=ti1;
    ti2[5]=20;
    cout << ti2[5] << endl;
    try{
        cout << ti2[-1] << endl;
    }
    catch(const IndexException &e){ 
        cerr << e.what() << endl;
    }

	return EXIT_SUCCESS;
}