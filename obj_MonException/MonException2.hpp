#include <exception>

class MonException2 : public MonException1 {
public:
    virtual const char *what() const noexcept override{
        return "What de MonException2";
    }
};