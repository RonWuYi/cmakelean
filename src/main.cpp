#include <iostream>
#include <cassert>
#include <charconv>
#include "Formula.h"
#include "header.h"
#include "components.h"

#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif
void *memset(void *, int, size_t);

#ifdef __cplusplus
}

#endif
int main(){
    using namespace interviewNew02;
    S<int> s = {1,2,3,4,5};
    s.append({6,7,8,9,10});

    std::cout << "the size is now " << s.c_arr().second << " ints:\n";
    for (int x : {-1, -2, -3})
        std::cout << x << ' ';

    auto al = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::cout << std::endl;
    std::cout << typeid(al).name() << '\n';

    templated_fn<std::initializer_list<int>>({1,2,3,4,5});

    char *str = (char*) malloc(sizeof(char) * 100);
    assert(str != nullptr);

    free(str);
    str = nullptr;
    
    return 0;
}
