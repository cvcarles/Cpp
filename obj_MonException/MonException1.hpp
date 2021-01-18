#include <exception>

class MonException1 : public std::exception {
public:
    virtual const char *what() const noexcept override{
        return "What de MonException1";
    }
};