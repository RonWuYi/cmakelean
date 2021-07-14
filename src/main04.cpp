// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <cstdlib>         
#include <ctime>
#include <future>         // std::
#include <utility>
#include <chrono>         // std::
#include <functional>
#include <atomic>         // std::
#include <mutex>         // std::
#include <map> // std::
#include <vector>         // std::
#include <algorithm>
#include <list> //
#include <numeric>

class Cents{
private:
    int m_cents;

public:
    Cents(int cents) : m_cents(cents){}
    int getCents() const { return m_cents; }

    friend Cents operator+(const Cents& a, const Cents& b);
    // int getCents() const { return m_cents; }
};


Cents operator+(const Cents& a, const Cents& b){
    return Cents(a.getCents() + b.getCents());
}

template <typename T>
inline void callWithMax(const T& a, const T& b) {
    f(a > b ? a : b);
}

int main()
{
    std::list<int> li(7);
    std::iota(li.begin(), li.end(), 0);

    std::cout << *std::min_element(li.begin(), li.end()) << std::endl;
    std::cout << *std::max_element(li.begin(), li.end()) << std::endl;

    Cents c1(100);
    Cents c2(200);

    Cents c3 = c1 + c2;
    std::cout << c3.getCents() << std::endl;
    return 0;
}



