#pragma once
#include <exception>
#include <string>

class IndexException : public std::exception{
private:
    std::string msg;
public:
    IndexException(const std::string s) : msg(s) {}

    virtual const char *what() const noexcept override{
        return this->msg.c_str();
    }
};

class IndexOverflow : public IndexException{
public:
    IndexOverflow(const int i) : IndexException("Index Overflow : " + std::to_string(i)) {}
};

class IndexUnderflow : public IndexException{
public:
    IndexUnderflow(const int i) : IndexException("Index Underflow : " + std::to_string(i)) {}
};