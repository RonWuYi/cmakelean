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

void print_container(const std::vector<int>& c)
{
    for (int i: c)
    {
        /* code */
        std::cout << i << " ";
    }
    std::cout <<'\n'; 
}

int main() {
    // Use();
    // std::string str {"hello"};
    // printReverse(str.c_str());
    // int i = 0;
    // std::cout << i << '\n';
    // std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int nine = 9;
    // for (std::vector<int>::iterator it = c.begin(); it != c.end();)
    // {
    //     // std::cout << it << '\n';
    //     if ( == nine)
    //     {
    //         /* code */
    //     }
        
    
    std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_container(c);
 
    c.erase(c.begin());
    print_container(c);
 
    c.erase(c.begin()+2, c.begin()+5);
    print_container(c);
 
    // Erase all even numbers (C++11 and later)
    for (std::vector<int>::iterator it = c.begin(); it != c.end(); ) {
        // if (*it % 2 == 0) {
        //     it = c.erase(it);
        // } else {
        //     ++it;
        // }

        if (*it == 0) {
            it = c.erase(it);
        }
    }
    print_container(c);
    return 0;
}