#include <iostream>
#include "Formula.h"

void print_vec(const std::vector<int>& vec)
{
    for (auto x: vec)
    {
        std::cout << ' ' << x << std::endl;
    }
    
}

int main() {
    MyQueue01 q;
    q.enQueue(5);
    q.enQueue(2);
    q.enQueue(17);
    q.enQueue(3);

    std::cout << q.Front() << std::endl;
    q.deQueue();
    std::cout << q.Front() << std::endl;
    q.enQueue(555);
    std::cout << q.Front() << std::endl;

    MyCircularQueue* obj = new MyCircularQueue(10);
    bool param_1 = obj->enQueue(11);
//  * bool param_2 = obj->deQueue();
//  * int param_3 = obj->Front();
//  * int param_4 = obj->Rear();
//  * bool param_5 = obj->isEmpty();
//  * bool param_6 = obj->isFull();
    return 0;
}