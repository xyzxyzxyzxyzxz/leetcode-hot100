// 85.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>


class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        std::vector<std::vector<int>> left(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        int res = 0;

        

        for (int j = 0; j <n; j++) {

            std::stack<int> mono_stk;
            std::vector<int> up(m, 0), down(m, 0);

            for (int i = m-1; i >= 0; i--) {
                while (!mono_stk.empty() && left[i][j] <= left[mono_stk.top()][j]) {
                    mono_stk.pop();
                }
                down[i] = mono_stk.empty() ? m : mono_stk.top();
                mono_stk.push(i);
            }

            mono_stk = std::stack<int>();

            for (int i = 0; i < m; i++) {
                while (!mono_stk.empty() && left[i][j] <= left[mono_stk.top()][j]) {
                    mono_stk.pop();
                }
                up[i] = mono_stk.empty() ? -1 : mono_stk.top();
                mono_stk.push(i);
            }

            for (int i = 0; i < m; i++) {
                res = std::max(res, (down[i] - up[i] - 1) * left[i][j]);
            }
        }


        return res;
    }
};

int main()
{
    std::vector<std::vector<char>> matrix = { {'0','0','0'},{'0','0','0'},{'1','1','1'} };

    Solution sol;
    int res = 0;
    res=sol.maximalRectangle(matrix);

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
