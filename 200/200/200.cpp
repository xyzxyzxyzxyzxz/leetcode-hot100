// 200.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

class Solution {
public:
    int m;
    int n;
    void dfs(std::vector<std::vector<char>>& grid, int r, int c) {
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1')dfs(grid, r - 1, c);
        if (r +1 < m && grid[r + 1][c] == '1')dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1')dfs(grid, r, c-1);
        if (c + 1 < n && grid[r][c+1] == '1')dfs(grid, r, c+1);

    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int num_island = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    num_island++;
                    dfs(grid, i, j);
                }
            }
        }

        return num_island;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
