// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <cstdlib>         
#include <ctime>
#include <future>         // std::


void foo() 
{
  // do stuff...
}

void bar(int x)
{
  // do stuff...
}

struct foo
{
    int a;
    int b;
    /* data */
} my_foo;


void long_operation()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(150ms);
}

int main(){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

    long_operation();

    auto t2 = high_resolution_clock::now();

    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms";
    return 0;
}