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

#ifdef __cplusplus
extern "C" {
#endif
void *memset(void *, int, size_t);

#ifdef __cplusplus
}

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

int main(){

    std::thread worker(worker_thread);

    string_data = "example data";

    {
        std::lock_guard lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }

    cv.notify_one();


    {
        std::unique_lock lk(m);
        cv.wait(lk, []{return processed;});
    }
    std::cout << "Back in main(), data = " << string_data << '\n';
    worker.join();
    return 0;
}