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

class Car {
public:
    virtual ~Car() = default;
    virtual void startEngine() = 0;
    virtual int getRunkSize() const = 0;
    virtual void addFuel(double quantity) = 0;
};

int main() {
    // std::unique_ptr<Foo> foo_ptr(make_Foo());

    // NoexceptCopy noexceptCopy;
    // NonNoexceptCopy nonNoexceptCopy;
    
    // std::cout << std::boolalpha << std::endl;
    
    // std::cout << "noexcept(copy(noexceptCopy)): " <<            // (4)
    //               noexcept(copy(noexceptCopy)) << std::endl;

    const int N = 1e3;
    auto my_arr = std::make_unique<std::array<int, N>>();

    for (int i = 0; i < N; i++) {
        my_arr->at(i) = i;
    }
    // auto count = 10; //
    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    //     auto cch = 'a' + rand()%26;

    //     std::cout << cch << std::endl;
    // }
    for (size_t i = 0; i < N; i++)
    {
        /* code */
        std::cout << my_arr->at(i) << std::endl;
    }
    

    return 0;
}