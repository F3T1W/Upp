#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() : data{ 0 } { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data{ data } { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

auto Make();
void Fill(std::vector<std::shared_ptr<Test>>& obj, int n);
void Display(const std::vector<std::shared_ptr<Test>>& obj);

auto Make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void Fill(std::vector<std::shared_ptr<Test>>& obj, int n) {
    int temp;
    for (int i = 1; i <= n; ++i) {
        std::cout << "Enter data point [" << i << "] : ";
        std::cin >> temp;
        obj.push_back(std::make_shared<Test>(temp));
    }
}

void Display(const std::vector<std::shared_ptr<Test>>& obj) {
    std::cout << "\nDisplaying vector data" << std::endl;
    std::cout << "=======================" << std::endl;
    for (const auto& ptr : obj) {
        std::cout << ptr->get_data() << std::endl;
    }
    std::cout << "=======================" << std::endl;
}

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = Make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    Fill(*vec_ptr, num);
    Display(*vec_ptr);
    return 0;
}