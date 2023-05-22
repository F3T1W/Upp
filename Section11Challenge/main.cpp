#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void DisplayInterface();
void AddNumber(vector<int> &numbers);
void DisplayNumbers(const vector<int>& numbers, size_t size);
void DisplayMean(const vector<int>& numbers, size_t size);
void DisplaySmallest(const vector<int>& numbers);
void DisplayLargest(const vector<int>& numbers);
void StartProgram(char& selectedOption, vector<int>& numbers);

int main() {
    char selectedOption{};
    vector<int> numbers;

    do {
        StartProgram(selectedOption, numbers);
    } while (selectedOption != 'q');
    return 0;
}

void DisplayInterface() {
    cout << '\n'
        << "P - Print numbers\n"
        << "A - Add a number\n"
        << "M - Display mean of the numbers\n"
        << "S - Display the smallest number\n"
        << "L - Display the largest number\n"
        << "Q - Quit\n"
        << '\n'
        << "Enter your choice: ";
}

void AddNumber(vector<int> &numbers) {
    int insertedNum;
    cout << endl;
    cout << "Enter a number: ";
    cin >> insertedNum;
    numbers.push_back(insertedNum);
}

void DisplayNumbers(const vector<int> &numbers, size_t size) {
    cout << '\n';
    for (int i {0}; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << '\n';
}

void DisplayMean(const vector<int> &numbers, size_t size) {
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    double mean = sum / size;
    cout << "\nYour mean is " << mean << '\n';
}

void DisplaySmallest(const vector<int>& numbers) {
    auto smallestIt = std::min_element(numbers.begin(), numbers.end());
    cout << "\nThe smallest number is " << *smallestIt << '\n';
}

void DisplayLargest(const vector<int>& numbers) {
    auto largestIt = std::max_element(numbers.begin(), numbers.end());
    cout << "\nThe largest number is " << *largestIt << '\n';
}

void StartProgram(char& selectedOption, vector<int>& numbers) {
    DisplayInterface();

    cin >> selectedOption;
    selectedOption = std::tolower(selectedOption);
    if (selectedOption == 'a') {
        AddNumber(numbers);
    }
    else if (numbers.empty()) {
        cout << "\nList is empty!\n";
    }
    else {
        switch (selectedOption) {
            case 'p': {
                DisplayNumbers(numbers, numbers.size());
                break;
            }
            case 'm': {
                DisplayMean(numbers, numbers.size());
                break;
            }
            case 's': {
                DisplaySmallest(numbers);
                break;
            }
            case 'l': {
                DisplayLargest(numbers);
                break;
            }
        }
    }
}