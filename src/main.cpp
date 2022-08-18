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

#ifdef __cplusplus
extern "C" {
#endif
void *memset(void *, int, size_t);

#ifdef __cplusplus
}

#endif

int main(){
    std::unordered_map<char, int> my_map;
    std::string s{"hello, world"};

    for (auto c : s) {
        my_map[c]++;
    }

    std::cout << my_map['l'] << std::endl;
    std::cout << my_map.size() << std::endl;
}