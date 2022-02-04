#include <iostream>
#include "Formula.h"

void print_vec(const std::vector<int>& vec)
{
    for (auto x: vec)
    {
        std::cout << ' ' << x << std::endl;
    }
    
}

class S {
public:
    S() {printf("default constructor\n");}
    ~S() {printf("destructor\n");}

    S(const S&) {printf("copy constructor\n");}
    S(S&&) {printf("move constructor\n");}
};

void Use()
{
    S obj {
        S{}
    };
}

void printReverse(const char *str) {
    if (!str) return;
    printReverse(str + 1);
    putchar(*str);
    // std::cout << *str << '\n';
}

int main() {
    // Use();
    // std::string str {"hello"};
    // printReverse(str.c_str());
    int i = 0;
    std::cout << i << '\n';
    return 0;
}