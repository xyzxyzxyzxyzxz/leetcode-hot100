// 22.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<std::string> res;

    std::vector<std::string> generateParenthesis(int n) {
        std::stack<char> sta;
        recur("", 0, n, sta);
        return res;
    }
    bool recur(std::string bra, int cur, int n, std::stack<char> sta) {
        if (cur == n && sta.empty()) {
            res.push_back(bra);
            return false;
        }
        if (cur == n + 1) {
            //    bra.push_back(')');
            //   sta.pop();

            return true;
        }
        sta.push('(');
        if (recur(bra + '(', cur + 1, n, sta)) {
            sta.pop();
        }


        if (!sta.empty()) {
            sta.pop();
            recur(bra + ')', cur, n, sta);
        }

        return false;
    }
};

int main()
{
    Solution sol;
    std::vector<std::string> res;
    res = sol.generateParenthesis(3);

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
