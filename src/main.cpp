#include <iostream>
#include <cassert>
#include <charconv>
#include "Formula.h"
#include "header.h"
#include "components.h"

#include <assert.h>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif
void *memset(void *, int, size_t);

#ifdef __cplusplus
}

#endif
int main(){
    std::vector<int> v{1,2,3,4,5};
    v.erase(v.begin() + 0);

    for (auto i : v) {
        std::cout << i << std::endl;
    }

    std::vector<std::pair<int, int>> p;
    auto temp = std::make_pair(1, 1);

    p.push_back(temp);
    auto temp2 = std::make_pair(2, 2);
    p.push_back(temp2);
    p.erase(p.begin() + 1);
    for (auto i : p) {
        std::cout << i.first << " " << i.second << std::endl;
    }
    return 0;

}