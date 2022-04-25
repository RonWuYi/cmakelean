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

int main() {
        const std::vector<Product> prods {
        { "box", 10.0 }, {"tv", 100.0}, {"none", -1.0}
    };

    auto out = [](const auto& v) { std::cout << v << ", "; };

    // standard version:
    std::cout << "std::for_each: \n";
    std::for_each(begin(prods), end(prods), [](const Product& p){
        std::cout << p.name_  << ", " << p.value_ << '\n';
    });

    std::cout << "std::for_each only names reverse: \n";
    std::for_each(rbegin(prods), rend(prods), [](const Product& p){
        std::cout << p.name_  << '\n';
    });

    // ranges version:
    std::cout << "std::ranges::for_each: \n";
    std::ranges::for_each(prods, [](const Product& p) {
        std::cout << p.name_  << ", " << p.value_ << '\n';
    });

    std::cout << "std::ranges::for_each only names in reverse: \n";
    std::ranges::for_each(prods | std::views::reverse, 
                          out, &Product::name_);
    {
        const std::vector<Product> prods {
        { "box", 10.0 }, {"tv", 100.0}, {"none", -1.0},
        { "car", 1000.0 }, {"toy", 40.0}, {"none", 0.0}
    };
    std::cout << "std::ranges::count_if: \n";
    // standard version:    
    auto res = std::count_if(begin(prods), end(prods), [](const Product& p){
        return p.name_.starts_with("no");
    });
    std::cout << "std::count_if: " << res << '\n';

    // ranges version:
    res = std::ranges::count_if(prods, [](const Product& p) {
        return p.name_.starts_with("no");
    });
    std::cout << "std::ranges::count_if: " << res << '\n';

    res = std::ranges::count(prods, std::string{"none"}, &Product::name_);
    std::cout << "std::ranges::count: " << res << '\n';
    }
}