#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) noexcept
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) noexcept
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) noexcept {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) noexcept {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 size_t Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

Mystring operator-(Mystring& obj) {
    char* buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (int i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{ buff };
    delete[] buff;
    return temp;
}

bool operator==(const Mystring& lhs, const Mystring& rhs) {
    if (std::strcmp(lhs.str, rhs.str) == 0)
        return true;
    else
        return false;
}

bool operator!=(const Mystring& lhs, const Mystring& rhs) {
    if (std::strcmp(lhs.str, rhs.str) == 0)
        return false;
    else
        return true;
}

bool operator<(const Mystring& lhs, const Mystring& rhs) {
    if (lhs.str < rhs.str)
        return true;
    else
        return false;
}

bool operator>(const Mystring& lhs, const Mystring& rhs) {
    if (lhs.str > rhs.str)
        return true;
    else
        return false;
}

Mystring operator+(const Mystring& lhs, const Mystring& rhs) {
    size_t buff_size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
    char* buff = new char[buff_size];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{ buff };
    delete[] buff;
    return temp;
}

Mystring& operator+=(Mystring& lhs, const Mystring& rhs) {
    lhs = lhs + rhs;
    return lhs;
}

Mystring operator*(const Mystring& lhs, int rhs) {
    size_t buff_size = std::strlen(lhs.str) * rhs + 1;
    char* buff = new char[buff_size];
    std::strcpy(buff, lhs.str);
    for (int i = 0; i < rhs - 1; i++) {
        std::strcat(buff, lhs.str);
    }
    Mystring temp{ buff };
    delete[] buff;
    return temp;
}

Mystring& operator*=(Mystring& lhs, int n) {
    lhs = lhs * n;
    return lhs;
}

Mystring& operator++(Mystring& obj) {
    for (int i = 0; i < std::strlen(obj.str); i++) {
        obj.str[i] = toupper(obj.str[i]);
    }
    return obj;
}

Mystring operator++(Mystring& lhs, int n) {
    Mystring temp(lhs);
    operator++(lhs);
    return temp;
}