#include "header.h"

std::mutex g_pages_mutex;

constexpr short BIG = 100;
constexpr short SMALL = 10;

void putCharQueueBig(charQueue &queue)
{
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    auto temp = std::make_unique<charData>();
    // std::fill(temp.get()->begin(), temp.get()->end(), 'a');

    for (size_t i = 0; i < BIG; i++)
    {
        /* code */
        // temp.get()->at(i) = 'a' + rand()%26;
        auto p = 'a' + rand()%26;
        // temp.get()[0][i] = p;
    }
}

void putIntQueueBig(intQueue &queue)
{
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    auto temp = std::make_unique<intData>();
    // auto length = 0;

    // while (true) {

    // }

    for (int i = 0; i < BIG; i++)
    {
        /* code */
        temp->at(i) = rand()%1000;
        // length++;
    }

    // while (true) {
    //     if (temp.get()[0][length] == temp.get()->end()) {
    //         // temp->at(length) = rand()%1000;
    //         // length++;
    //         break;
    //     }
    // }

    // while (true)
    // {
    //     if (temp.get()[0][length] == temp.get()[0].end())
    //     {
    //         // length++;
    //         break;
    //     }
    //     // else
    //     // {
    //     //     break;
    //     // }))
    //     // {
    //     //     break;
    //     // }
    //     // auto length = temp.get()[0]->size();
    //     // temp.get()[0][length] = rand()%100;
    //     temp->at(0)[0] = rand()%100;
    //     length++;
    // }
    queue.push(std::move(temp));

}

void getIntQueueBig(intQueue &queue)
{
    std::lock_guard<std::mutex> guard(g_pages_mutex);

    auto p = queue.size();
    std::cout << "queue size: " << p << std::endl;
}

// void popIntQueueBig(intQueue &queue, intQueueSmall &queueSmall)
// {
//     std::lock_guard<std::mutex> guard(g_pages_mutex);

//     if (!queue.empty())
//     {
//         auto temp = queue.front();
//         queue.pop();
//     }
// }
int factorial(int n) {
	if (n < 1) return 1;
	else return n * factorial(n - 1);
}

// template <class T>
// T mysum(T a[], int n) {
// 	T theSum = 0;
// 	for (int i = 0; i < n; i++) {
// 		theSum += a[i];
// 	}
// 	return theSum;
// }
