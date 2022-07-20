#include <iostream>
#include <cassert>
#include "Formula.h"
#include "header.h"

int main(){
    std::string s{"abcdefghTF"};
    for (auto p: s)
    {
        std::cout << p << std::endl;
    }

    std::string s1{"A man, a plan, a canal: Panama"};

    std::string temp{};
    for (auto p: s1)
    {
        if (p >= 'A' && p <= 'z')
        {
            if (p > 'Z')
                p = p - 32;
            temp += p;
        }
    }
    std::cout << temp << std::endl;

}