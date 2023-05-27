#include <iostream>

using namespace std;

int main() {
    const float smallCost{ 25.0 };
    const float largeCost{ 35.0 };
    const double saleTax{ 0.06 };

    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << endl;
    cout << "How many small rooms would you like cleaned? ";

    unsigned short smallRooms{ 0 };

    cin >> smallRooms;

    cout << "How many large rooms would you like cleaned? ";

    unsigned short largeRooms{ 0 };

    cin >> largeRooms;

    cout << endl;
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << smallRooms << endl;
    cout << "Number of large rooms: " << largeRooms << endl;
    cout << "Price for small room: $" << smallCost << endl;
    cout << "Price for large room: $" << largeCost << endl;

    float taxlessCost = (smallRooms * smallCost) + (largeRooms * largeCost);

    cout << "Cost: $" << taxlessCost << endl;

    double tax = taxlessCost * saleTax;

    cout << "Tax: $" << tax << endl;
    cout << "===============================" << endl;
    cout << "Total estimate: $" << taxlessCost + tax << endl;
    cout << "This estimate is valid for 30 days" << endl;

    return 0;
}