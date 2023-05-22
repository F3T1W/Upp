#include <iostream>

using namespace std;

int main() {
    const int million{ 1'000'000 };
    const int thousand{ 1000 };
    const int hundred{ 100 };
    const int ten{ 10 };

    long long unsigned int sum{ 0 };

    cout << "Enter sum in rouble: ";

    cin >> sum;

    cout << "Millions: " << sum / million << '\n'
         << "Thousands: " << (sum % million) / thousand << '\n'
         << "Hundreds: " << (sum % thousand) / hundred << '\n'
         << "Tens: " << (sum % hundred) / ten << '\n'
         << "Roubles: " << sum % ten << '\n';

    return 0;
}
