#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    //----------------------------------------------------------------------- MY CODE
    friend Mystring operator-(Mystring& obj); // -

    friend bool operator==(const Mystring& lhs, const Mystring& rhs); // ==

    friend bool operator!=(const Mystring& lhs, const Mystring& rhs); // !=

    friend bool operator<(const Mystring& lhs, const Mystring& rhs); // <

    friend bool operator>(const Mystring& lhs, const Mystring& rhs); // >

    friend Mystring operator+(const Mystring& lhs, const Mystring& rhs); // +

    friend Mystring& operator+=(Mystring& lhs, const Mystring& rhs); // +=

    friend Mystring operator*(const Mystring& lhs, int rhs); // *

    friend Mystring& operator*=(Mystring& lhs, int n); // *=

    friend Mystring& operator++(Mystring& obj); // pre-increment ++

    friend Mystring operator++(Mystring& lhs, int n); // post-increment ++
    //-------------------------------------------------------------------------------
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                        // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source) noexcept;                    // Copy constructor
    Mystring( Mystring &&source) noexcept;                         // Move constructor
    ~Mystring();                                                      // Destructor
    
    Mystring& operator=(const Mystring& rhs) noexcept;     // Copy assignment
    Mystring& operator=(Mystring &&rhs) noexcept;           // Move assignment
    
    void display() const;
    
    size_t get_length() const;                                      // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_