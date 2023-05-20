#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    char selectedOption{};
    vector<int> numbers;

    do {
        cout << '\n'
            << "P - Print numbers\n"
            << "A - Add a number\n"
            << "M - Display mean of the numbers\n"
            << "S - Display the smallest number\n"
            << "L - Display the largest number\n"
            << "Q - Quit\n"
            << '\n'
            << "Enter your choice: ";

        cin >> selectedOption;
        selectedOption = std::tolower(selectedOption);
        if (selectedOption == 'a') {
            int insertedNum;
            cout << endl;
            cout << "Enter a number: ";
            cin >> insertedNum;
            numbers.push_back(insertedNum);
        }
        else if (numbers.empty()) {
            cout << "\nList is empty!\n";
        }
        else {
            switch (selectedOption) {
                case 'p': {
                    cout << '\n';
                    for (auto number : numbers) {
                        cout << number << " ";
                    }
                    cout << '\n';
                    break;
                }
                case 'm': {
                    double sum = std::accumulate(numbers.begin(), numbers.end(), 0);
                    double mean = sum / numbers.size();
                    cout << "\nYour mean is " << mean << '\n';
                    break;
                }
                case 's': {
                    auto smallestIt = std::min_element(numbers.begin(), numbers.end());
                    cout << "\nThe smallest number is " << *smallestIt << '\n';
                    break;
                }
                case 'l': {
                    auto largestIt = std::max_element(numbers.begin(), numbers.end());
                    cout << "\nThe largest number is " << *largestIt << '\n';
                    break;
                }
            }
        }
    } while (selectedOption != 'q');
    return 0;
}