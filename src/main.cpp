#include <iostream>
#include <cassert>
#include <charconv>
#include "Formula.h"
#include "header.h"
#include "components.h"
#include <assert.h>
#include <unordered_set>
#include <vector>
#include <memory>

#ifdef __cplusplus
extern "C" {
#endif
void *memset(void *, int, size_t);

#ifdef __cplusplus
}

#endif

int main(){
    auto p1 = rvalue::make_unique1<rvalue::A>(2);
    int i = 1;
    auto p2 = rvalue::make_unique1<rvalue::A>(i);

    std::cout << "B\n";

    auto t = rvalue::make_unique2<rvalue::B>(2, i, 3);

    rvalue::MemoryBlock block;
    rvalue::f(block);
    rvalue::f(rvalue::MemoryBlock());

    string s1{"first"};

    rvalue::print_type_and_value(s1);
    rvalue::print_type_and_value(string("third"));
    // rvalue::print_type_and_value(rvalue::fourth());

    std::cout << 567 / 100 << std::endl;
    std::cout << 567 / 10 << std::endl;
    std::cout << 567 / 1 << std::endl;
    std::cout << 567 % 100 << std::endl;

    SolutionisHappy s{};

    std::cout << s.isHappy02(19) << std::endl;

    // std::expected<int, std::string> e = 43;
    return 0;
}