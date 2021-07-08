#include <iostream>
#include <cassert>
#include <sstream>         // std::
#include <string>
#include <cstring>         // std::

bool f(int &r) { return &r != nullptr; }

class Foo
{
public:
    explicit Foo(int foo) : m_foo(foo)
    {}

    int GetFoo() const { return m_foo; }
private:
    int m_foo;
};

void DoBar(Foo foo)
{
    int i = foo.GetFoo();
    std::cout << i << std::endl;
}

class Person
{
    // std::string name;
    char* name;
    int age;

public:
    // Person(const std::string &name, int age)
    //     :name(name), age(age)
    // {}
    Person(const char* the_name, int the_age)
    {
        name = new char[strlen(the_name) + 1];
        strcpy(name, the_name);
        age = the_age;
    }

    Person(const Person& that)
    {
        name = new char[strlen(that.name) + 1];
        strcpy(name, that.name);
        age = that.age;
    }

    // Person& operator=(const Person& that)
    // {
    //     if (this != &that)
    //     {
    //         /* code */
    //         delete [] name;
    //         name = new char[strlen(that.name) + 1];
    //         strcpy(name, that.name);
    //     }
    //     return *this;
        
    // }
    Person& operator=(const Person& that)
    {
        char* local_name = new char[strlen(that.name) + 1];
        strcpy(local_name, that.name);

        delete [] name;
        name = local_name;

        age = that.age;
        return *this;

    }

    ~Person()
    {
        delete [] name;
    }

};

int main()
{
    std::string s = "Somewhere down the road";

    std::istringstream iss(s);

    do
    {
        std::string subs;
        iss >> subs;
        std::cout << subs << std::endl;
    } while (iss);
    
    return 0;

    int number = 5;
    // std::alpha;
    number |= 1UL << 2;
    std::cout << std::boolalpha;
    std::cout << number << std::endl;

    char c = 'a';

    c |= 1UL << 2;
    std::cout << c << std::endl;

    Person a("BJ", 5);
    Person b(a);
    b = a;
    // assert(a == b);
    return 0;
}