// 84.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>


class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();

        std::vector<int> left(n), right(n);

        std::stack<int> mono_stk;

        for (int i = 0; i < n; i++) {
            while (!mono_stk.empty()&&heights[i]<=heights[mono_stk.top()]) {
                mono_stk.pop();
            }
            left[i] = mono_stk.empty() ? -1 : mono_stk.top();
            mono_stk.push(i);
        }

        mono_stk = std::stack<int>();

        for (int i = n - 1; i >= 0; i--) {
            while (!mono_stk.empty() && heights[i] <= heights[mono_stk.top()]) {
                mono_stk.pop();
            }
            right[i] = mono_stk.empty() ? n : mono_stk.top();
            mono_stk.push(i);
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            res = std::max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
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
