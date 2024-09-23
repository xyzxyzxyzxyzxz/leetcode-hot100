// 301.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


class Solution {
public:
    
    std::unordered_set<std::string> resset;
    void deleunne(std::string str, int ind, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(str)) {
                resset.emplace(str);
            }
            return;
        }

        for (int i = ind; i < str.size(); i++) {
            if (lremove + rremove > str.size() - i) {
                return;
            }

            if (lremove > 0 && str[i] == '(') {
                deleunne(str.substr(0, i) + str.substr(i + 1), i, lremove - 1, rremove);
            }
            if (rremove > 0 && str[i] == ')') {
                deleunne(str.substr(0, i) + str.substr(i + 1), i, lremove, rremove - 1);
            }
        }

    }

    inline bool isValid(std::string str) {
        int cnt = 0;
        for (char c : str) {
            if (c == '(') {
                cnt++;
            }
            else if (c == ')') {
                if (cnt == 0) {
                    return false;
                }
                else {
                    cnt--;
                }
            }
        }

        return cnt == 0;
    }

    std::vector<std::string> removeInvalidParentheses(std::string s) {
        int lremove = 0, rremove = 0;

        for (char c : s) {
            if (c == '(') {
                lremove++;
            }
            else if (c == ')') {
                if (!lremove) {
                    rremove++;
                }
                else {
                    lremove--;
                }
            }
        }

        deleunne(s, 0, lremove, rremove);
        std::vector<std::string> res(resset.begin(), resset.end());

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
