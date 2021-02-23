#pragma once

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

template <int M, int N, typename T>
class SetValue : public Command {
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
class AddValue : public Command {
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