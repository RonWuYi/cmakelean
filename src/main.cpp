#include <iostream>
#include "Formula.h"

int main() {
    std::cout << "Bla: " << Formula::bla(2) << std::endl;
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::string s{"Hello"};
    std::cout << "Hello: " << s.size() << std::endl;
    std::cout << "Hello: " << s.length() << std::endl;
    v.push_back(6);
    for (auto i : v) {
        std::cout << i << std::endl;
    }
    std::for_each(v.rbegin(), v.rend(), [](const int n) { std::cout << n << ' '; });
    return 0;
}