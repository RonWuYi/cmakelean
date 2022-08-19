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

#ifdef __cplusplus
extern "C" {
#endif
void *memset(void *, int, size_t);

#ifdef __cplusplus
}

#endif

int main(){
    int a[] = {1,2,3,4,5};
    std::span<int> s(a);

    std::cout << s.size() << std::endl;
    std::cout << s.data() << std::endl;
    std::cout << s.front() << std::endl;
    std::cout << s.back() << std::endl;

    std::span<int>::element_type et = s[3];
    std::cout << et << std::endl;

    return 0;
}