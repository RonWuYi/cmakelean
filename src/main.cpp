#include <iostream>
#include <cassert>
#include <charconv>
#include "Formula.h"
#include "header.h"
#include "components.h"
#include <assert.h>
#include <unordered_set>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif
void *memset(void *, int, size_t);

#ifdef __cplusplus
}

#endif
int main(){
    std::unordered_set<int> hashset;

    hashset.insert(1);
    hashset.insert(2);
    hashset.insert(3);

    hashset.insert(3);

    std::cout << hashset.size() << std::endl;
}