#include <iostream>
#include "Formula.h"

void print_vec(const std::vector<int>& vec)
{
    for (auto x: vec)
    {
        /* code */
        std::cout << ' ' << x << std::endl;
    }
    
}

int main() {
    std::vector<int> vec(3, 100);
    print_vec(vec);
    std::cout << '\n';
    auto it = vec.begin();
    it = vec.insert(it, 200);
    print_vec(vec);

    std::cout << '\n';
    vec.insert(it, 2, 300);
    print_vec(vec);
    std::cout << '\n';

    it = vec.begin();

    std::vector<int> vec2(2, 400);

    // print_vec(vec2);
    std::cout << '\n';
    vec.insert(it+2,vec2.begin(), vec2.end());
    print_vec(vec);
    std::cout << '\n';
    int arr[] = { 501,502,503 };
    vec2.insert(vec2.begin(), arr, arr+3);
    print_vec(vec2);
    return 0;
}