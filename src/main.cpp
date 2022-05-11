#include <iostream>
#include <cassert>
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

constexpr bool IsPresent(std::string_view pattern, std::string_view str) {
    auto it =std::search(str.begin(), str.end(), 
                         std::default_searcher(pattern.begin(), pattern.end()));

    return it != str.end();
}

void printSting(std::string&& str) {
    std::cout << str << '\n';
}

struct President {
    std::string name;
    std::string country;
    int year;

    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(std::move(p_year))
    {
        std::cout << "President constructor\n";
    }

    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year((other.year))
    {
        std::cout << "President move constructor\n";
    }
    President& operator=(const President& other) = default;
};

using namespace std::chrono;
using shared_ptr_t = std::shared_ptr<int>;

void shared_ptr_receiver_by_value(shared_ptr_t ptr) {
    (void)*ptr;
}

void shared_ptr_receiver_by_ref(const shared_ptr_t& ptr) {
    (void)*ptr;
}

void test_copy_by_value(uint64_t n) {
    auto ptr = std::make_shared<int>(100);
    for (uint64_t i = 0u; i < n; ++i) {
        shared_ptr_receiver_by_value(ptr);
    }
}

void test_copy_by_ref(uint64_t n) {
    auto ptr = std::make_shared<int>(100);
    for (uint64_t i = 0u; i < n; ++i) {
        shared_ptr_receiver_by_ref(ptr);
    }
}

void test_shared_ptr(size_t n) {
    std::cout <<__FUNCTION__ << '\n';
    std::vector<shared_ptr<size_t>> v;
    // STD::shared_ptr<>
    v.reserve(n);
    for (size_t i = 0u; i < n; ++i) {
        v.push_back(std::shared_ptr<size_t>(new size_t(i)));
    }
}

void test_make_shared(size_t n) {
    std::cout <<__FUNCTION__ << '\n';
    std::vector<std::shared_ptr<size_t>> v;
    v.reserve(n);
    for (size_t i = 0u; i < n; ++i) {
        v.push_back(std::make_shared<size_t>(i));
    }
}

int main(int argc, char const *argv[]) {
    uint64_t n = (argc == 3) ? std::stoull(argv[2]) : 100;
    auto t1 = high_resolution_clock::now();

    if (atoi(argv[1]) == 1) {
        test_copy_by_value(n);
    }
    else
    {
        test_copy_by_ref(n);
    }

    auto t2 = high_resolution_clock::now();

    auto time_span = duration_cast<duration<int64_t, std::micro>>(t2 - t1);
    std::cout << "It take me " << time_span.count() << " microseconds.\n";
    return 0;
}