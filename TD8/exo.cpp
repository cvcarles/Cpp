#include <iostream>
#include <cstdlib>

#include "MonException1.hpp"
#include "MonException2.hpp"

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
    throw 40;
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
    cerr << "C'est fini ... je ne tiens plus ... arrrgh" << endl;
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
    /*try {
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
    }*/
    
    try{
        fprime();
        gprime();
    }
    catch(const MonException2 &e){

    }
    catch(const MonException1 &e){

    }


	return EXIT_SUCCESS;
}