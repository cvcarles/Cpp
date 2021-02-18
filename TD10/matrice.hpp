#pragma once
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <cassert>
#include <sstream> 

template <int M, int N, typename T>
class Matrice {
public:
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = std::remove_cv_t<T>;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        pointer position;

        iterator (pointer p) : position(p) {}
        iterator &operator++() {
            this->position++;
            return *this;
        }
        iterator operator++(int) {
            iterator i = *this;
            this->position++;
            return i;
            }
        reference operator*() const {return *this->position;}
        pointer operator->() const {return this->position;}
        bool operator==(const iterator &it) {return this->position == it.position;}
        bool operator!=(const iterator &it) {return this->position != it.position;}
    };
    class const_iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = std::remove_cv_t<T>;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        pointer position;

        const_iterator (pointer p) : position(p) {}
        iterator &operator++() {
            this->position++;
            return *this;
        }
        iterator operator++(int) {
            iterator i = *this;
            this->position++;
            return i;
            }
        reference operator*() const {return *this->position;}
        pointer operator->() const {return this->position;}
        bool operator==(const iterator &it) {return this->position == it.position;}
        bool operator!=(const iterator &it) {return this->position != it.position;}
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
        return this->mat[index];
    }

    iterator begin() noexcept{return iterator(mat);}

    iterator end() noexcept{return iterator(mat+size);}

    std::string toString() const {
        std::ostringstream s;
        for (int i=0; i < M; i++) {
            for (int j=0; j < N; j++) s << this->mat[N*i+j] << " ";
            s << "\n";
        }
		return s.str();
    }

    friend std::ostream &operator<<(std::ostream &f, const Matrice<M,N,T> &matrice) {
        return f << matrice.toString();
    }
};