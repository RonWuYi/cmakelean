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
    auto length = 0;

    // while (true) {

    // }

    for (int i = 0; i < BIG; i++)
    {
        /* code */
        temp->at(i) = rand()%100;
        length++;
    }


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
    // queue.push(std::move(temp));

}