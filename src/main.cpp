#include <iostream>
#include "Formula.h"
#include "header.h"

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

struct ParamType;

template<typename T>
void f(T& param);

struct Product {
    std::string name_;
    double value_ {0.0};
};

using var_t = std::variant<int, long, double, std::string>;

template<class> inline constexpr bool always_false_v = false;

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };

template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main() {
    std::vector<var_t> vec = {10, 15l, 1.5, "hello"};
    // std::cout << vec[0] << '\n';
    // std::cout << std::get<0>(vec) << '\n';
    for(auto& v : vec) {
        std::visit([](auto&& arg) {
            std::cout << arg << '\n';
        }, v);

        var_t w = std::visit([](auto&& arg) ->var_t {return arg + arg;}, v);
    }
}