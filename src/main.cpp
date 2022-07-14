#include <iostream>
#include <cassert>
#include "Formula.h"
#include "header.h"

int main(){

    MyQueueStack qs;

    qs.push(1);
    qs.push(2);

    std::cout << "qs.peek() = " << qs.peek() << std::endl;
    std::cout << "qs.pop() = " << qs.pop() << std::endl;
    std::cout << "qs.empty() = " << qs.empty() << std::endl;

    B bbb;
    bbb.print_ptr();
    C ccc;
    ccc.print_ptr();

    std::unordered_map<std::string, std::string> u = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FFF"}
    };

    auto print_key_value = [](const auto& key, const auto& value) {
        std::cout <<"key: " <<key << " value: "<< value << std::endl;
    };

    for (const std::pair<const std::string, std::string>& n : u)
    {
        print_key_value(n.first, n.second);
    }
    
    return 0;
}