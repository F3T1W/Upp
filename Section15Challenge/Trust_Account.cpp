#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{ name, balance, int_rate } {
}

bool Trust_Account::deposit(double amount) {
    if (balance >= 0) {
        if (balance >= 5000) {
            balance += def_bonus;
            Account::deposit(amount);
            return true;
        }
        else {
            Account::deposit(amount);
            return true;
        }
    }
    else
        return false;
}

bool Trust_Account::withdraw(double amount) {
    if (_withdraw_count >= 4 || (amount > balance * 0.2)) {
        return false;
    }
    else
        ++_withdraw_count;
        Savings_Account::withdraw(amount);
}

std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate
        << "%, withdrawals: " << account._withdraw_count << "]";
    return os;
}

