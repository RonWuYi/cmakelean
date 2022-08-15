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
    std::unordered_set set{2, 7, 1, 8, 2, 8, 1, 8, 2, 8};
    std::cout << "the set is: ";

    for (int e: set)
    {
        std::cout << e << ' ';
    }

    const auto [min, max] = std::ranges::minmax(set);

    std::cout << "min " << min << " to  max " << max << std::endl;

    for (int i{min}; i<= max; ++i)
    {
        if (set.count(i) == 1)
            std::cout << i << ' ';
    }
    std::string p{"hello"};
    
    std::unordered_map<char, int> tmp;
    for (auto& t: p)
        // std::cout << t << std::endl;
    {
        if (!tmp.empty())
        {
            for (auto& tt: tmp)
            {
                if (tt.first == t)
                {
                    tt.second += 1;
                    break;
                }
            }
            tmp.emplace(t, 0);
        }
    }


}