#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__

#include <exception>

using namespace std;

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
    virtual const char* what() const noexcept {
        return "Insufficent funds exception";
    }
};

#endif // ___INSUFFICIENT_FUNDS_EXCEPTION_H__