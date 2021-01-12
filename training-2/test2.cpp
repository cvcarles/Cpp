#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class String {
protected:
    char *st;
    int lg;
public:
    String(char *c = (char *)"") : s(c), lg(strlen(c)) {}
    String(const String &s) { dupliquer(s); }

    void dupliquer(const String &s) {
        this->st = new char[this->lg = s.lg+1]
        strcpy(this->st, s.st);
    }

    const String &operator=(const String &s) const { dupliquer(s); }
    const String &operator+(const String &s) const {
        String rs;
        rs.st = new char[ch.lg = s.lg+this->lg];
        rs.st = strcpy(rs.st, this->st);
        rs.st = strcat(rs.st, s.st);
        return rs;
    } 

    friend const std::ostream &operator<<(const std::ostream &f, const String &s) {
        for (int i=0; i<s.lg; i++) f << s.st[i];
        return f;
    }
};

int main(){

    return EXIT_SUCCESS;
}