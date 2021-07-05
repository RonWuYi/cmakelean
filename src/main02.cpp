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

struct bank_account
{
    explicit bank_account(const std::string& name, int money)
    {
        sName = name;
        iMoney = money;
    }

    std::string sName;
    int iMoney;
    std::mutex mMutex;
};

void transfer(bank_account &from, bank_account &to, int amount)
{
    std::unique_lock<std::mutex> lock1(from.mMutex, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.mMutex, std::defer_lock);

    std::lock(lock1, lock2);

    from.iMoney -= amount;
    to.iMoney += amount;
    std::cout << "Transfer " << amount << " from " << from.sName << " to " << to.sName << std::endl;
}


std::mutex my_lock;

void add(int &num, int &sum)
{
    while (true)
    {
        std::lock_guard<std::mutex> lock(my_lock);

        if (num < 100)
        {
            /* code */
            num += 1;
            sum += num;
        }
        else
        {
            break;
        }
    }
}


struct sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};

struct Foo {
    void display_greeting() { std::cout << "hello" << std::endl; }

    void display_number(int i) { std::cout << "number: " << i << std::endl;}
    int data = 7;
};

int main()
{
    bank_account Account1("User1", 100);
    bank_account Account2("User2", 50);

    std::thread t1([&]() { transfer(Account1, Account2, 10);});
    std::thread t2([&]() { transfer(Account2, Account1, 5);});

    t1.join();
    t2.join();

    std::cout << "Account1 have " << Account1.iMoney << '\n';
    std::cout << "Account2 have " << Account2.iMoney << '\n';

    int sum = 0;
    int num = 0;

    std::vector<std::thread> ver;

    for (size_t i = 0; i < 20; ++i)
    {
        /* code */
        std::thread t = std::thread(add, std::ref(num), std::ref(sum));
        ver.emplace_back(std::move(t));
    }

    for (auto &p : ver)
    {
        p.join();
        /* code */
    }
    
    // std::for_each(ver.cbegin(), ver.cend(), std::mem_fn(std::thread::join));
    std::cout << sum << '\n';

    std::vector<int> nums{3, 4, 2, 8, 15, 256};
    auto print = [](const int& n) { std::cout << " " << n;};
    std::cout << "before;";
    std::for_each(nums.cbegin(), nums.cend(), print);

    Foo f;
    std::cout << '\n';

    auto greet = std::mem_fn(&Foo::display_greeting);
    greet(&f);

    auto print_num = std::mem_fn(&Foo::display_number);
    print_num(&f, 42);

    auto access_data = std::mem_fn(&Foo::data);
    std::cout << "data: " << access_data(&f) << '\n';
    return 0;
}