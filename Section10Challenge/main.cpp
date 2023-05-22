#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main() {
    constexpr std::string_view alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ " };
    constexpr std::string_view key     { "1QAZqaz2WSXwsx3EDCedBc4RFVrf3Ov5TGBtgb6YHNyhn7UJMPCS " };

    static_assert(alphabet.size() == key.size());
    
    string enteredMessage{ "" };

    getline(cin, enteredMessage);

    for (auto& x : enteredMessage) {
        size_t pos = alphabet.find_last_of(x);
        x = key[pos];
    }

    cout << enteredMessage;

    return 0;
}
