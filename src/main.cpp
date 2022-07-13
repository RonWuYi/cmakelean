#include <iostream>
#include <cassert>
#include "Formula.h"
#include "header.h"

int main(){

    MyQueueStack qs;

    qs.push(1);
    qs.push(2);

    std::cout << "qs.peek() = " << qs.peek() << std::endl;
    std::cout << "qs.pop() = " << qs.pop() << std::endl;
    std::cout << "qs.empty() = " << qs.empty() << std::endl;

    B bbb;
    bbb.print_ptr();
    C ccc;
    ccc.print_ptr();

    return 0;
}