#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source) noexcept;                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs) noexcept;           // Move assignment

    //-------------------------------------------- MY CODE

    Mystring operator-() const; // -

    bool operator==(const Mystring& rhs) const; // ==

    bool operator!=(const Mystring& rhs) const; // !=

    bool operator<(const Mystring& rhs) const; // <

    bool operator>(const Mystring& rhs) const; // >

    Mystring operator+(const Mystring& rhs) const; // +

    Mystring& operator+=(const Mystring& rhs); // +=

    Mystring operator*(int n) const; // *

    Mystring& operator*=(int n); // *=

    Mystring& operator++(); // pre-increment ++

    Mystring operator++(int n); // post-increment ++

    //--------------------------------------------
    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_