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


int g_i = 0;
std::mutex g_i_mutex;

void safe_increment()
{
    std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
    std::cout << std::this_thread::get_id() << " : " << g_i << std::endl;
}

std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;
 
void save_page(const std::string &url)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";
 
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    g_pages[url] = result;
}
 
struct Box
{
    explicit Box(int num) : num_things(num) {}
    int num_things;
    std::mutex m;
};

void transfer(Box &from, Box &to, int num)
{
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

    std::lock(lock1, lock2);

    from.num_things -= num;
    to.num_things += num;
}

int main()
{
    std::cout << "main: " << g_i << '\n';
 
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    t2.join();
 
    std::cout << "main: " << g_i << '\n';

    Box acc1(100);
    Box acc2(50);
    
    std::thread tbox1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread tbox2(transfer, std::ref(acc2), std::ref(acc1), 5);

    tbox1.join();
    tbox2.join();
    return 0;
}