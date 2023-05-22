#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<int> vector1;
    std::vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    std::cout << "First vector -> " << vector1.at(0) << ", " << vector1.at(vector1.size() - 1) << std::endl;

    vector2.push_back(100);
    vector2.push_back(200);

    std::cout << "Second vector -> " << vector2.at(0) << ", " << vector2.at(vector2.size() - 1) << std::endl;

    std::vector<std::vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    std::cout << "Vector_2d -> first vector (before change) -> " << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << std::endl;

    vector1.at(0) = 1000;

    std::cout << "Vector_2d -> first vector (after change) -> " << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << std::endl;
    std::cout << "Vector_2d -> second vector -> " << vector_2d.at(1).at(0) << ", " << vector_2d.at(1).at(1) << std::endl;
    std::cout << "First vector (after change) -> " << vector1.at(0) << ", " << vector1.at(vector1.size() - 1) << std::endl;

    return 0;
}