#include <iostream>
#include <cassert>
#include "Formula.h"
#include "header.h"
#include "components.h"

int main(){

    node::ListNode* ln1 = new node::ListNode(1);
    node::ListNode* ln2 = new node::ListNode(2);
    node::ListNode* ln3 = new node::ListNode(3);
    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln1;

    node::SolutionhasCycle* shc = new node::SolutionhasCycle();

    if (shc->hasCycle(ln1))
        std::cout << "has" << std::endl;
    else
        std::cout << "does not have" << std::endl;

    delete ln1;
    delete ln2;
    delete ln3;
    delete shc;
    
    return 0;
}