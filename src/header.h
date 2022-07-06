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
	// void push(int x) {
	// 	data.push_back(x);
	// }
	// int pop() {
	// 	int ret = data[p_start];
	// 	p_start++;
	// 	return ret;
	// }
	// int peek() {
	// 	return data[p_start];
	// }
	// bool empty() {
	// 	return p_start == data.size();
	// }
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