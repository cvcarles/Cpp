#include "IndexException.hpp"
#include <sstream>

template <int N, typename T>
class tableau {
private:
    T elem[N];
public:
    tableau(const T &v=T()){
        for(int i=0; i<N; i++) this->elem[i] = v;
    }

    tableau(const std::initializer_list<T> &l){
        int i=0;
        for(T x : l) this->elem[i++] = x;
        for(; i<N; i++) this->elem[i] = T();
    }

    tableau(const tableau<N,T> &t){
        for(int i=0; i<N; i++) this->elem[i]=t.elem[i];
    }

    int longueur() const{
        return N;
    }

    const std::string toString() const{
        std::ostringstream s;
        s << "[ ";
        for(int i=0; i<N; i++) s << this->elem[i] << " ";
        s << "]";
        return s.str();
    }

    friend std::ostream &operator<< (std::ostream &f, tableau<N,T> &t){
	return f << t.toString();
}

    T &operator[](int i){
        if (i>=N) throw IndexOverflow(i); 
        else if (i<0) throw IndexUnderflow(i); 
        return this->elem[i];
    }

    tableau<N,T> &operator=(tableau<N,T> t){
        for (int i=0; i<N; i++) this->elem[i] = t.elem[i];
        return *this;
    }
};