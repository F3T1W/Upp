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
