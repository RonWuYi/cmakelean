#include "header.h"

std::mutex g_pages_mutex;

constexpr short BIG = 100;
constexpr short SMALL = 10;

void putCharQueueBig(charQueue &queue)
{
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    auto temp = std::make_unique<charData>();
    // std::fill(temp.get()->begin(), temp.get()->end(), 'a');

    for (size_t i = 0; i < BIG; i++)
    {
        /* code */
        // temp.get()->at(i) = 'a' + rand()%26;
        auto p = 'a' + rand()%26;
        // temp.get()[0][i] = p;
    }
}

void putIntQueueBig(intQueue &queue)
{
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    auto temp = std::make_unique<intData>();
    // auto length = 0;

    // while (true) {

    // }

    for (int i = 0; i < BIG; i++)
    {
        /* code */
        temp->at(i) = rand()%1000;
        // length++;
    }

    // while (true) {
    //     if (temp.get()[0][length] == temp.get()->end()) {
    //         // temp->at(length) = rand()%1000;
    //         // length++;
    //         break;
    //     }
    // }

    // while (true)
    // {
    //     if (temp.get()[0][length] == temp.get()[0].end())
    //     {
    //         // length++;
    //         break;
    //     }
    //     // else
    //     // {
    //     //     break;
    //     // }))
    //     // {
    //     //     break;
    //     // }
    //     // auto length = temp.get()[0]->size();
    //     // temp.get()[0][length] = rand()%100;
    //     temp->at(0)[0] = rand()%100;
    //     length++;
    // }
    queue.push(std::move(temp));

}

void getIntQueueBig(intQueue &queue)
{
    std::lock_guard<std::mutex> guard(g_pages_mutex);

    auto p = queue.size();
    std::cout << "queue size: " << p << std::endl;
}

// void popIntQueueBig(intQueue &queue, intQueueSmall &queueSmall)
// {
//     std::lock_guard<std::mutex> guard(g_pages_mutex);

//     if (!queue.empty())
//     {
//         auto temp = queue.front();
//         queue.pop();
//     }
// }
int factorial(int n) {
	if (n < 1) return 1;
	else return n * factorial(n - 1);
}

// template <class T>
// T mysum(T a[], int n) {
// 	T theSum = 0;
// 	for (int i = 0; i < n; i++) {
// 		theSum += a[i];
// 	}
// 	return theSum;
// }
int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void SolutionwallsAndGates::wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.size() == 0) { return; }
    for (int row = 0; row < rooms.size(); row++) {
        for (int col = 0; col < rooms[0].size(); col++) {
            if (rooms[row][col] == EMPTY) {
                rooms[row][col] = distanceTonearestGates(rooms, row, col);
            }
        }
    }
}

int SolutionwallsAndGates::distanceTonearestGates(std::vector<std::vector<int>>& rooms, int startRow, int startCol)
{
    int m = rooms.size();
    int n = rooms[0].size();

    std::vector<std::vector<int>> distance{};
    std::queue<std::array<int, 2>> q{};
    // auto temp = std::array<int, 2>(startRow, startCol);
    // q.push(temp);
    // while (!q.empty()) {
    //     auto temp = q.front();
    //     q.pop();
    //     int row = temp[0];
    //     int col = temp[1];
    //     for (auto& direction: DIRECTIONS)
    //     {
    //         int r = row + direction[0];
    //         int c = col + direction[1];

    //         // if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] == WALL
    //         //         || direction[r][c] != 0)
    //         //         continue;
    //     }
    // }
    return 0;

}


void SolutionwallsAndGatesNew::wallsAndGates(vector<vector<int>>& rooms) {
    const int row = rooms.size();
    if (row == 0) return;
    const int col = rooms[0].size();
    queue<pair<int,int>> canReach;  
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // four directions for each reachable

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            auto temp = rooms[i][j];
            if (0 == rooms[i][j])
            {
                canReach.emplace(i, j);
            }
        }
    }

    while (!canReach.empty()) {
        int r = canReach.front().first, c = canReach.front().second;
        canReach.pop();
        for (auto dir: dirs) {
            int x = r + dir.first, y = c + dir.second;
            if (x < 0 || y < 0 || x >= row || y >= col || rooms[x][y] <= rooms[r][c])
                continue;
            auto temp1 = rooms[x][y];
            auto temp2 = rooms[r][c];
            rooms[x][y] = rooms[r][c] + 1;
            canReach.emplace(x, y);
        }
    }

}

void C::print_ptr()
{
    std::cout << "print_ptr" << std::endl;
    bc->print_ptr();
    ba->print_ptr();
}
