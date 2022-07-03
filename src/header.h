#pragma once

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

// template <class T>
// T mysum(T a[], int n);
