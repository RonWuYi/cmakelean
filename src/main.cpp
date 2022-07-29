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
    // auto t = cpp17::str("1234"s);

    std::vector<cpp20::Task> tasks {
        {"clean up my room", 10}, {"finish work", 5}, {"go to sleep", 0}, {"buy new monitor", 12}
    };

    auto print = [](cpp20::Task& t) {
        std::cout << "Task: " << t.desc << ", priority: " << t.priority << '\n';
    };

    std::ranges::sort(tasks, std::ranges::greater{},
    &cpp20::Task::priority);

    std::cout << "my next priorities: \n";
    std::ranges::for_each(tasks, print);

    std::vector v {1, 2, 3, 4, 5};
    cpp20::CallOnRange(v, [](int& i) {
        std::cout << "i: " << i << '\n';
    });

    std::cout << std::endl;
    cpp20::GameActor actor { "robot", "a friendly type" };
    std::cout << "actor is: " << std::invoke(&cpp20::GameActor::name, actor) << '\n';
    std::cout << "desc is: " << std::invoke(&cpp20::GameActor::desc, actor) << '\n';
    
    auto ptr = std::make_unique<cpp20::GameActor>("space ship", "slow");
    std::cout << "actor is: " << std::invoke(&cpp20::GameActor::name, ptr) << '\n';

    return 0;
}