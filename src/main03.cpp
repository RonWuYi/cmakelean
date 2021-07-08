#include <iostream>
#include <cassert>


bool f(int &r) { return &r != nullptr; }



int main()
{
    int x = 5;
    int y = 6;
    int *p;
    p = &x;
    p = &y;
    *p = 10;
    assert(x == 5);
    assert(y == 10);
    int xx = 5;
    int yy = 6;

    // int &q;
    int &r = yy;
    int *pp = &yy;
    int *p2 = &r;

    assert(pp == p2);
    assert(&pp != &p2);

    int &rr = *static_cast<int *>(nullptr);

    std::cout << (&rr != nullptr ? "not null" : "null") << '\n';

    // prints "not null" under GCC 10
    std::cout<< (f(*static_cast<int *>(nullptr))
        ? "not null" : "null")
    << std::endl;
    return 0;
}