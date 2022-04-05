#include <iostream>
#include "Formula.h"

struct PrintNum {
    void operator()(int i) const {
        std::cout << i << '\n';
    }
};

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
    return n1;
}

struct Foo {
    void print_sum(int n1, int n2)
    {
        std::cout << n1 + n2 << '\n';
    }
    int data = 10;
};

int main() {
      std::vector<std::reference_wrapper<int*>> numbers;
  
  int* a = new int{42};
  numbers.push_back(a);
  
  int* b = new int{51};
  numbers.push_back(b);
  
  int* c = new int{66};
  numbers.push_back(c);


  delete b;
  b = nullptr;

  for (auto n : numbers) {
    if (n == nullptr) { 
        std::cout << "nullptr found \n";
        continue; 
    }
    std::cout << *n.get() << '\n';
  }
  std::cout << '\n';
  std::cout << numbers.size() << '\n';
  
  delete numbers[2].get();
  numbers[2].get() = nullptr;
  std::cout << "c is " << (c == nullptr ? "nullptr" : std::to_string(*c)) << '\n'; 
}