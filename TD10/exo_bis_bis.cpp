#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <sstream>
#include <map>
#include <cassert>

using namespace std;

template <int M, int N, typename T>
class Matrice {
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::remove_cv_t<T>;
        using pointer = T*;
        using reference = T&;
    private:
        pointer position;
    public: 
        iterator (pointer p) : position(p) {}
        iterator &operator++() {return ++this->position;}
        iterator operator++(int) {return this->position++;}
        reference operator*() const {return *this->position;}
        pointer operator->() const {return &this->position;}
        bool operator==(const iterator &it) {return this->position == it;}
        bool operator!=(const iterator &it) {return this->position != it;}
    };
protected:
    const int size = M*N;
    T *mat;
public:
    Matrice(const T &v = T()) : mat(new T[size]) {
        for (int i=0; i < this->size; i++) this->mat[i] = v;
    }
    ~Matrice() {delete [] this->mat;}

    T &operator()(int i, int j) {
        int index = N*i+j;
        assert(index >= 0 and index < this->size);
        return *this->mat[index];
    }

    std::string toString() {
        std::ostringstream s;
        s << "[";
        for (int i; i < M; i++) {
            for (int j; j < N; j++) {
                s << this->mat[N*i+j] << " ";
            }
            s << "\n";
        }
		return s.str();
    }

    friend std::ostream &operator<<(std::ostream &f, const Matrice<M,N,T> &matrice) {
        return f << matrice.toString();
    }
};

int main(){
    const int M=2;
    const int N=3;
    Matrice<M,N,int> m;

    /*for (Matrice<M,N,int>::iterator it = m.begin(); it!=m.end(); it++){
        cout << *it << " " << endl;
    }*/

    return EXIT_SUCCESS;
}