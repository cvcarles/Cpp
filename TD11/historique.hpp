#pragma once
#include <vector>
#include <iterator>
#include <cassert>

template <typename T>
class History {
public:
    virtual void put(const T &x) =0;
    virtual bool empty() const =0;
    virtual bool before() const =0;
    virtual bool after() const =0;
    virtual bool is_first() const =0;
    virtual bool is_last() const =0;
    virtual void back() =0;
    virtual void forth() =0;
    virtual const T &item() const =0;
    virtual void remove_all_right() =0;
    bool on_item() const {
        return !this->empty() && !this->before() && !this->after();
    }
};

template <typename T>
class HistoryList : public History<T> {
protected:
    std::vector<T> hl;
    typename std::vector<T>::iterator cursor;
public:
    HistoryList() : cursor(this->hl.begin()-1) {}
    void put(const T &x) {
        this->hl.push_back(x);
        this->cursor = this->hl.end()-1;
    }
    bool empty() const {return this->hl.empty();}
    bool before() const {return cursor < this->hl.begin();}
    bool after() const {return cursor >= this->hl.end();}
    bool is_first() const {return cursor == this->hl.begin();}
    bool is_last() const {return cursor == this->hl.end()-1;}
    void back() {if (!this->before()) this->cursor--;}
    void forth() {if (!this->after()) this->cursor++;}
    const T &item() const {
        assert(this->on_item());
        return *this->cursor;
    }
    void remove_all_right() {this->hl.erase(this->cursor+1, this->hl.end());}
};