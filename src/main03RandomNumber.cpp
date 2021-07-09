#include <iostream>
#include <cassert>
#include <sstream>         // std::
#include <string>
#include <cstring>         // std::
#include <cstdlib>         // std::

#include <ctime>


int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int count = 100;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        std::cout << std::rand() << '\t';

        if (i % 5 == 0)
        {
            std::cout << '\n';
            /* code */
        }
        
    }
    
}
