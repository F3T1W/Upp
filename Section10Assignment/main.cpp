#include <iostream>
#include <string>

using namespace std;

int main() {
    string enteredMessage{ "" };
    string lastLine("");
    size_t lastPos{ 0 };

    getline(cin, enteredMessage);

    cout << endl;

    for (size_t j{ 0 }; j < enteredMessage.size(); ++j) {
        cout << " ";
    }

    cout << enteredMessage.at(0);

    for (size_t j{ 0 }; j < enteredMessage.size(); ++j) {
        cout << " ";
    }

    cout << endl;

    lastLine = enteredMessage.at(0);

    for (size_t i{ 1 }; i < enteredMessage.size(); ++i) {

        for (size_t j{ enteredMessage.size() - (i - 1) }; j > 1; j--) {
            cout << " ";
        }

        lastPos = lastLine.find(static_cast<size_t>(enteredMessage[i - 1]));

        string temp(1, enteredMessage[i]);
        string temp2(1, enteredMessage[i - 1]);
        string finalTemp = temp + temp2;

        lastLine.insert(lastPos + 1, finalTemp);

        cout << lastLine;
        cout << endl;
    }

    return 0;
}

/* Issue #4 Solution
#include <iostream>
#include <string>
#include <iomanip>

void print_n_spaces(size_t n) {
    std::cout << std::setfill(' ') << std::setw(n) << ' ';
}

void print_pattern(std::string_view s, size_t end) {
    const size_t count_to_print = 2 * end + 1;

    print_n_spaces(s.size() - end + 1);
    for (size_t i = 0; i < count_to_print; ++i) {
        char current = i <= end ? s[i] : s[count_to_print - (i + 1)];
        std::cout << current;
    }
    print_n_spaces(s.size() - end + 1);

    std::cout << "\n";
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::cout << '\n';
    for (size_t i = 0; i < line.size(); ++i) {
        print_pattern(line, i);
    }
    return 0;
}
*/