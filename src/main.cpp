#include <iostream>
#include "Formula.h"

struct PrintNum {
    void operator()(int i) const {
        std::cout << i << '\n';
    }
};

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
    return n1;
}

struct Foo {
    Foo() {std::cout << "Leak?" << std::endl;}
    Foo(const Foo &&) {std::cout << "Move constructor?" << std::endl;}
    ~Foo() {std::cout << "No leak" << std::endl;}
};

struct IntContainer {
    IntContainer() : int_ptr(new int(0)) {}
    ~IntContainer() { delete int_ptr; }

    int* get_ptr() const { return int_ptr;}
    int* int_ptr;
};

Foo* make_Foo() {return new Foo();}

void compute(Foo* foo)
{
    delete foo;
}

class NoexceptCopy {
public:
    std::array<int, 5> arr{1, 2, 3, 4, 5};

};

class NonNoexceptCopy {
public:
    std::vector<int> v{1, 2, 3, 4, 5};
};

template<typename T>
T copy(T const& src) noexcept(noexcept(T(src))){
    return src;
}

int main() {
    std::unique_ptr<Foo> foo_ptr(make_Foo());

    NoexceptCopy noexceptCopy;
    NonNoexceptCopy nonNoexceptCopy;
    
    std::cout << std::boolalpha << std::endl;
    
    std::cout << "noexcept(copy(noexceptCopy)): " <<            // (4)
                  noexcept(copy(noexceptCopy)) << std::endl;
    return 0;
}