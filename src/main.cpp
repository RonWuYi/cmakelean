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
    MyQueue q;
    q.enQueue(5);
    q.enQueue(2);
    q.enQueue(17);
    q.enQueue(3);

    std::cout << q.Front() << std::endl;
    q.deQueue();
    std::cout << q.Front() << std::endl;
    q.enQueue(555);
    std::cout << q.Front() << std::endl;
    return 0;
}