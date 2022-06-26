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

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t_) {}

    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

struct func{
    int y;
    func(int x) : y(x) {}
    void operator()() const {
        std::cout << "Hello, world from func\n";
    }
};

void do_something_in_current_thread() {
    std::cout << "do something in current thread!\n";
}

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);

    do_something_in_current_thread();

}
struct widget_id
{
    /* data */
};

struct widget_data
{};

void display_status()
{
    std::cout << "display_status\n";
}

void process_widget_data(widget_data data)
{
    std::cout << "process_widget_data\n";
}

struct W
{
    W(int&, int&) {}
};

struct X
{
    X(const int&, int&) {}
};

struct Y
{
    Y(int&, const int&) {}
    /* data */
};

struct Z
{
    /* data */
    Z(const int&, const int&) {}
};

template<typename T, typename A1, typename A2>
T* factory(A1&& a1, A2&& a2)
{
    //return new T(std::forward<A1>(a1), std::forward<A2>(a2));
    return new T(a1, a2);
}

class MemoryBlock{};

void f(const MemoryBlock&) {
    std::cout << "f(const MemoryBlock&)\n";
}

void f(MemoryBlock&&)
{}

void f123(const std::string &&value)
{
    std::cout << "from f()\n";
    std::cout << "value is " << value << '\n';
    std::cout << "thread id is "<< std::this_thread::get_id << '\n';
}

class Box {
public:
    Box() = delete;
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height){}

    Box (const Box& other) = delete;
private:
    int m_width;
    int m_length;
    int m_height;

};

void Endianness()
{
    int a = 0x12345678;
    if (*((char*)&a) == 0x12)
    {
        std::cout << "Big Endian" << std::endl;
    }
    else
    {
        std::cout << "Little Endian" << std::endl;
    }
}

int main(){

    Box box1(1, 2, 3);
    Box box2{ 2, 3, 4 };
    Endianness();
    // Box box3; // C2512: no appropriate default constructor available
}