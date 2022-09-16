#include <iostream>
#include <cassert>
#include <charconv>
#include "Formula.h"
#include "header.h"
#include "components.h"
#include <assert.h>
#include <ostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <span>
#include <condition_variable>
#include <atomic>
#include <typeinfo>

// #include "spdlog/spdlog.h"

#include "spdlog/sinks/basic_file_sink.h"

#if 0
#ifdef __cplusplus
extern "C" {
#endif

void *memset(void *, int, size_t);

#ifdef __cplusplus
}
#endif 

#endif

std::mutex m;
std::condition_variable cv;
std::string string_data;

bool ready = false;
bool processed = false;

void worker_thread()
{
    std::unique_lock lk(m);
    cv.wait(lk, []{return ready;});

    std::cout << "worker thread is processing data\n";

    string_data += "after processing";
    processed = true;

    std::cout << "Worker thread signals data processing completed\n";
    lk.unlock();    
    cv.notify_one();
}

void worker_thread_no_cv()
{
    std::unique_lock lk(m);
    // cv.wait(lk, []{return ready;});

    std::cout << "worker thread no cv is processing data\n";

    string_data += "after processing no cv ";
    processed = true;

    std::cout << "Worker thread no cv signals data processing completed\n";
    lk.unlock();    
    // cv.notify_one();
}

struct S {
    char a;
    int b : 5;
    int e;
    double f;
    std::string g;
};

class Spinlock {
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
    void lock() {
        while (flag.test_and_set());
    }

    void unlock() {
        flag.clear();
    }
};

Spinlock spin;

void workOnResource() {
    spin.lock();
    spin.unlock();
}

void print(int id, const std::vector<int>& container)
{
    std::cout << id << ". ";

    for (const int x: container)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

vector<int> plusOne(vector<int>& digits) {
    int temp = 0;
    int carry = 0;

    for (size_t i = digits.size()-1; i > 0; i--)
    {
        if (i == digits.size()-1) {
            if ((digits[i] + 1) >= 10) {
                carry = 1;
                temp = (digits[i] + 1) % 10;
            } else {
                    temp = (digits[i] + 1);
                    }
        } else {
            if ((digits[i] + carry) >= 10) {
                carry = 1;
                temp = (digits[i] + carry) % 10;
            } else {
                temp = (digits[i] + carry);
            }
        }
        digits[i] = temp;
    }

    if (carry > 0)
    {
        auto it = digits.begin();
        digits.insert(it, carry);
    }
    return digits;
}

int main(){


    string s1 = "Hello World";
    // 1. concatenate
    s1 += "!";
    cout << s1 << endl;
    // 2. find
    cout << "The position of first 'o' is: " << s1.find('o') << endl;
    cout << "The position of last 'o' is: " << s1.rfind('o') << endl;
    // 3. get substr
    cout << s1.substr(5, 5) << endl;
    cout << "string part" << endl;
    cout << typeid(s1[0]).name() << endl;  // int
    cout << typeid(s1.substr(1,1)).name() << endl;  // int
    cout << "################################" << endl;
    std::vector<int> nums {1, 2, 4, 8, 16};

    for (auto i = nums.rbegin(); i != nums.rend(); ++i)
        std::cout << *i << endl; // int

    vector<int> v{111, 222, 333, 456, 89};

    auto p = std::find(v.begin(), v.end(), 456);

    if (p != v.end())
        cout << *p << endl; // int
}