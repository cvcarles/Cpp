#pragma once
#include <sstream>

class Command {
public:
    virtual void execute() =0;
    virtual void undo() =0;
    virtual void redo() {this->execute();}
};


class Undoable_Command : public Command {
public:
    virtual void execute() =0;
    virtual void undo() =0;
};

template <int M, int N, typename T>
class SetValue : public Undoable_Command {
private:
    Matrice<M,N,T> *mat;
    int i, j;
    T pred_value;
    T value;
public:
    SetValue(Matrice<M,N,T> *matrice, int m, int n, const T &val) : mat(matrice), i(m), j(n), value(val) {}
    virtual void execute() override {
        this->pred_value =  (*(this->mat))(this->i, this->j);
        (*(this->mat))(this->i, this->j) = this->value;
    }
    virtual void undo() override {
        (*(this->mat))(this->i, this->j) = this->pred_value;
    }
};

template <int M, int N, typename T>
class AddValue : public Undoable_Command {
private:
    Matrice<M,N,T> *mat;
    T value;
public:
    AddValue(Matrice<M,N,T> *matrice, const T &val) : mat(matrice), value(val) {}
    virtual void execute() override {
        for (auto it = (*(this->mat)).begin(); it != (*(this->mat)).end(); it++) *it+=this->value;
    }
    virtual void undo() override {
        for (auto it = (*(this->mat)).begin(); it != (*(this->mat)).end(); it++) *it-=this->value;
    }
};

class Non_Undoable_Command : public Command {
public:
    virtual void execute() =0;
    virtual void undo() =0;
};

template <int M, int N, typename T>
class display : public Non_Undoable_Command {
private:
    Matrice<M,N,T> *mat;
public:
    display(Matrice<M,N,T> *matrice) : mat(matrice) {}
    virtual void execute() override {
        std::cout << (*(this->mat)) << std::endl;
    }
    virtual void undo() override {}
};

class help : public Non_Undoable_Command {
private:
    std::ostringstream message;
public:
    help() {
        this->message << "s (v, l, c) pour mettre la valeur v en (l,c) dans la matrice" << std::endl;
        this->message << "a (v) pour ajouter la valeur v à tous les éléments de la matrice" << std::endl;
        this->message << "p pour afficher la matrice sur la sortie standard" << std::endl;
        this->message << "u undo la dernière commande" << std::endl;
        this->message << "r redo la dernière commande" << std::endl;
        this->message << "h pour afficher une aide" << std::endl;
        this->message << "q pour quitter le système intéractif" << std::endl;
    }
    virtual void execute() override {
        std::cout << this->message.str();
    }
    virtual void undo() override {}
};

/*class quit: public Non_Undoable_Command {
public:
    virtual void execute() override {
        return EXIT_SUCCESS;
    }
};*/