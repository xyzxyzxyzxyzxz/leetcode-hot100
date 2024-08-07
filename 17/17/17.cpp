// 17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>




class Solution {
public:
    std::string dig_map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    std::string s;
    std::vector<std::string> res;
    void backtrace(std::string digits, int ind) {
        if (ind == digits.size()) {
            res.push_back(s);
            return;
        }
        int num = 0;
        num = digits[ind] - '0';
        for (int i = 0; i < dig_map[num].length(); i++) {
            s.push_back(dig_map[num][i]);
            backtrace(digits, ind + 1);
            s.pop_back();
        }
    }
    std::vector<std::string> letterCombinations(std::string digits) {
        s.clear();
        res.clear();
        if (digits.length() == 0) {
            return res;
        }
        backtrace(digits, 0);
        return res;
    }
};





int main()
{
    Solution sol;
    std::vector<std::string>res;
    res=sol.letterCombinations("23");
    return 0;
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
