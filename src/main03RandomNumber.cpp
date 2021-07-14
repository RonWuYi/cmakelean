#include <iostream>
#include <cassert>
#include <sstream>         // std::
#include <string>
#include <cstring>         // std::
#include <cstdlib>         // std::
#include <chrono>
#include <ctime>

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::steady_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now())
	{
	}
	
	void reset()
	{
		m_beg = clock_t::now();
	}
	
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Timer t;
    int count = 1000;
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
    std::cout << t.elapsed() <<std::endl;
    return 0;
}
