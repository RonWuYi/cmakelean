#include <iostream>
#include <cassert>
#include <charconv>
#include "Formula.h"
#include "header.h"
#include "components.h"

int main(){
    for (std::string_view const str : {"1234", "15 foo", "bar", " 42", "43  ", "5000000000"}) {
        std::cout << "String: " <<std::quoted(str) << ". ";

        int result{};

        auto [ptr, ec] {std::from_chars(str.data(), str.data() + str.size(), result)};

        if (ec == std::errc())
        {
            // std::cout << "Result: " << result

            std::cout << "Result: " << result << ", ptr -> " << std::quoted(ptr) << '\n';
        }
        else if (ec == std::errc::invalid_argument)
        {
            std::cout << "it is not a number\n";
        }

        else if (ec == std::errc::result_out_of_range)
        {
            std::cout << "this number is larger than an int\n";
        }
    }


    return 0;
}