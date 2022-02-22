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

struct Baz {
    // int a;
 
    std::function<void()> foo() {
        return [=] {
            std::cout << s << '\n';
        };
    }

    std::string s;
};

int main() {
    struct
    {
        void operator()(int x) const
        {
            std::cout << x << '\n';
        }
    } someInstance;
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    std::for_each(v.begin(), v.end(), someInstance);

    std::for_each(v.begin(), v.end(), [] (int x){
        std::cout << x << '\n';
    });

    auto myLambda = [](int x) mutable {
        std::cout << x << '\n';
    };

    int x = 1, y = 2;

    std::cout << x << '\n';

    auto foo = [&x, &y] () {++x;++y; };
    foo();
    std::cout << x << " " << y << '\n';

    auto f1 = Baz{"ala"}.foo();
    auto f2 = Baz{"ula"}.foo();

    f1();
    f2();
    return 0;
}