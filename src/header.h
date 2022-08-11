#pragma once

#include <cstdint> //or <stdint.h>
#include <limits>
#include <array>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <type_traits>
#include <variant>
#include <utility>
#include <list>
#include <bitset>
#include <cmath>
#include <unordered_set>


using namespace std;
using charQueue = std::queue<std::unique_ptr<std::array<char, 100>>>;
using charQueueSmall = std::queue<std::unique_ptr<std::array<char, 10>>>;

using charData = std::unique_ptr<std::array<char, 100>>;
using charDataSmall = std::unique_ptr<std::array<char, 10>>;

using intQueue = std::queue<std::unique_ptr<std::array<int, 100>>>;
using intQueueSmall = std::queue<std::unique_ptr<std::array<int, 10>>>;

using intData = std::array<int, 100>;
using intDataSmall = std::array<int, 10>;

void putCharQueueBig(charQueue &queue);
void putIntQueueBig(intQueue &queue);
void popIntQueueBig(intQueue &queue, intQueueSmall &queueSmall);
void getIntQueueBig(intQueue &queue);

int factorial(int n);

int Fibonacci(int n);

template <class T>
T mysum02(T a[], int n)
{
	T theSum = 0;
	return accumulate(a, a+n, theSum);
}

template <class T>
T product(T a[], int n)
{
	T theSum = 1;
	return accumulate(a, a+n, theSum, multiplies<T>());
}

template <class T>
T product01(T a[], int n, int m)
{
	T theSum = 1;
	return accumulate(a+n, a+m, theSum, multiplies<T>());
}

template <class T>
void rank(T a[], int n, int r[])
{
	for (int i = 0; i < n; ++i)
		r[i] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i] < a[j])
				++r[i];
			else r[j]++;
}

template <class T>
void rearrange(T a[], int n, int r[])
{
	T *u = new T[n];

	for (int i = 0; i < n; ++i)
		u[r[i]] = a[i];
	for (int i = 0; i < n; ++i)
	{
		a[i] = u[i];
	}
}

class MyQueue {
private:
	vector<int> data;
	int p_start;
public:
	MyQueue() : p_start(0) {}

	bool enQueue(int x)
	{
		data.push_back(x);
		return true;
	}
	bool deQueue()
	{
		if (isEmpty())
			return false;
		p_start++;
		return true;
	}
	int Front() { return data[p_start]; } 

	bool isEmpty() { return p_start >= data.size(); }
};

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};

class SolutionwallsAndGates {
public:
	// int EMPTY = INT_MAX;
	// int GATE = 0;
	// int WALL = -1;
	// std::list<std::array<int,2>> DIRECTIONS{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    virtual void wallsAndGates(vector<vector<int>>& rooms);
	// {
	// 	if (rooms.size() == 0) { return; }
	// 	for (int row = 0; row < rooms.size(); row++) {
	// 		for (int col = 0; col < rooms[0].size(); col++) {
	// 			if (rooms[row][col] == EMPTY) {
	// 				rooms[row][col] = distanceTonearestGates(rooms, row, col);
	// 			}
	// 		}
	// 	}
        
    // }
private:
	int distanceTonearestGates(std::vector<std::vector<int>>& rooms, int startRow, int startCol);
	int EMPTY = INT_MAX;
	int GATE = 0;
	int WALL = -1;
	std::list<std::array<int,2>> DIRECTIONS{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	// std::list<int[][]>> DIRECTIONS{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

class SolutionwallsAndGatesNew : public SolutionwallsAndGates
{
public:
    virtual void wallsAndGates(vector<vector<int>>& rooms);
};

class SolutionmaxArea {
public:
    int maxArea(vector<int>& height) {

        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int area = (j - i) * min(height[i], height[j]);
            if (area > max)
            {
                max = area;
            }
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return max;
        
    }
};

class SolutionfindComplement {
public:
    int findComplement(int num) {
        std::string binary = std::bitset<32>(num).to_string();
        std::string sub;

        for (auto i = 0; i < binary.size(); i++)
        {
            if (binary[i] == '1')
            {
                sub = binary.substr(i);
                break;
            }
        }

        for (auto i = 0; i < sub.size(); i++)
        {
            if (sub[i] == '1')
                sub[i] = '0';
            else
                sub[i] = '1';
        }

        auto num2 = stoi(sub, nullptr, 2);


        return num2;
    }
};


class MyQueueStack {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
    // int index;
public:
    MyQueueStack() {
    }
    
    void push(int x) {
       stack1.push(x); 
    }
    
    int pop() {
        int res = peek();
        stack2.pop();
        return res;
    }
    
    int peek() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        return res;
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

class MyStackQueue {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;
public:
    MyStackQueue() {
        
    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        int res = top();
        queue1.pop();
        return res;
    }
    
    int top() {
        if (!queue1.empty())
        {
            while (queue1.size() > 1)
            {
                queue2.push(queue1.front());
                queue1.pop();
            }
            int res = queue1.back();
            return res;
        }
        int res = queue1.back();
        return res;
    }
    
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};

class MyStackQueue01 {
private:
    std::queue<int> q;

public:
    MyStackQueue01(){}
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int res = top();
        q.pop();
        return res;
    }

    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

struct PrintNum {
    void operator()(int i) const {
        std::cout << i << '\n';
    }
};

template<typename T>
T copy(T const& src) noexcept(noexcept(T(src))){
    return src;
}

struct ParamType;

template<typename T>
void f(T& param);

struct Product {
    std::string name_;
    double value_ {0.0};
};

using var_t = std::variant<int, long, double, std::string>;

template<class> inline constexpr bool always_false_v = false;

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };

template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

struct President {
    std::string name;
    std::string country;
    int year;

    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(std::move(p_year))
    {
        std::cout << "President constructor\n";
    }

    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year((other.year))
    {
        std::cout << "President move constructor\n";
    }
    President& operator=(const President& other) = default;
};

using namespace std::chrono;
using shared_ptr_t = std::shared_ptr<int>;

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t_) {}

    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

class A {
public:
    A() {
        b = std::make_unique<int>(22);
        std::cout << "A constructor\n";
    }
    A(const A& other) {
        std::cout << "A copy constructor\n";
    }
    A(A&& other) {
        std::cout << "A move constructor\n";
    }
    A& operator=(const A& other) {
        std::cout << "A copy assignment\n";
        return *this;
    }
    A& operator=(A&& other) {
        std::cout << "A move assignment\n";
        return *this;
    }

    void print_ptr() const {
        std::cout << *(b.get()) << '\n';
    }

private:
    int a;
    std::unique_ptr<int> b;
};

class B {
public:
    B() {
        std::cout << "B constructor\n";
    }
    B(const B& other) {
        std::cout << "B copy constructor\n";
    }
    B(B&& other) {
        std::cout << "B move constructor\n";
    }
    B& operator=(const B& other) {
        std::cout << "B copy assignment\n";
        return *this;
    }
    B& operator=(B&& other) {
        std::cout << "B move assignment\n";
        return *this;
    }

    void print_ptr() const {
        aa.print_ptr();
    }
private:
    int a;
    A aa;
};

class C
{
public:
    C() {
        bc = std::make_unique<B>();
        ba = std::make_unique<A>();
        std::cout << "C constructor\n";
    }
    void print_ptr();

private:
    std::unique_ptr<B> bc;
    std::unique_ptr<A> ba;
};


namespace tree {
    struct Node {
        char data;
        Node* left;
        Node* right;
    };

    void preOrder(tree::Node *root);
    void preOrderNoRecursive(tree::Node *root);

    void inOrder(tree::Node *root);
    void postOrder(tree::Node *root);

}

// namespace interviewNew {
//     class A {
//     private:
//         const int a;  
//     public:
//         A() : a(0) {};
//         A(int x) : a(x) {};

//         int getValue();
//         int getValue() const;
//     };

//     void function()
//     {
//         A b;
//         const A a;
//         const A *p = &a;
//         const A &q = a;
//     }

//     class Base {
//     public:
//         inline virtual void who() {
//             std::cout << "Base\n";
//         };
//         virtual ~Base() {};
//     };

//     class Derived : public Base {
//     public:
//         inline void who() override {
//             std::cout << "Derived\n";
//         }
//     };
// }
// void preOrder(tree::Node *root);
// void preOrder(tree::Node *root) {
//     std::cout << root->data;
//     preOrder(root->left);
//     preOrder(root->right);
// }

// void preOrderNoRecursive(tree::Node *root);
//     std::stack<tree::Node*> s; 
//     tree::Node *p = root;
//     while (p != nullptr || !s.empty()) {
//         while (p != nullptr) {
//             std::cout << p->data << " ";
//             s.push(p);
//             p = p->left;
//         }
//         if (!s.empty())
//         {
//             p = s.top();
//             s.pop();
//             p = p->right;
//         }
//     }
// }

// void inOrder(tree::Node *root);
//     preOrder(root->left);
//     std::cout << root->data;
//     preOrder(root->right);
// }

// void postOrder(tree::Node *root) {
//     preOrder(root->left);
//     preOrder(root->right);
//     std::cout << root->data;
// }
namespace interviewNew01 {
    class A {
    private:
        const int a;  
    public:
        A() : a(0) {};
        A(int x) : a(x) {};

        int getValue();
        int getValue() const;
    };

    class Base {
    public:
        inline virtual void who() {
            std::cout << "Base\n";
        };
        virtual ~Base() {};
    };

    class Derived : public Base {
        public:
            inline void who() override {
                std::cout << "Derived\n";
            }
    };

    struct AA {
        AA(int a) {}
        operator bool() const { return true; }
    };

    struct BB {
        explicit BB(int b) {}
        explicit operator bool() const { return true; }
    };
}

namespace interviewNew02 {
    // int count = 11;

    // class A {
    // public:
    //     static int count;
    // };
    // int A::count = 21;

    // void func01();
    template<typename It>
    auto fcn(It beg, It end) -> decltype(*beg) {
        return *beg;
    }

    template<typename It>
    auto func2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type {
        return *beg;
    }

    template<class T>
    struct S {
        std::vector<T> v;
        S(std::initializer_list<T> l) : v(l) {
            std::cout << "constructed with a " << l.size() << "-element initializer list\n";
        }

        void append(std::initializer_list<T> l) {
            v.insert(v.end(), l.begin(), l.end());
        }

        std::pair<const T*, std::size_t> c_arr() const {
            return {&v[0], v.size()};
        }
    };

    template<typename T>
    void templated_fn(T) {}
}

namespace polymorphism {
    class AAA {
    public:
        void doabcd(int a);
        void doabcd(int a, int b);
    };
}

namespace lambda {
    template<typename T>
    bool findDuplicates(vector<T>& vec) {
        std::unordered_set<T> s;
        for(T key: vec) {
            if(s.find(key) != s.end()) {
                return true;
            }
            s.insert(key);
        }
        return false;
    }
}

namespace rvalue {
    struct W {
        W(int&, int&) {}
    };

    struct X {
        X(const int&, int&) {}
    };

    struct Y {
        Y(int&, const int&) {}
    };

    struct Z {
        Z(const int&, const int&) {}
    };
}