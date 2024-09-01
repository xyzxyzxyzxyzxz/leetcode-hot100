// 76.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <unordered_map>


class Solution {
public:
    std::unordered_map<char,int> ori, cnt;

    bool check() {
        for (const auto &elem : ori) {
            if (cnt[elem.first] < elem.second) {
                return false;
            }
        }
        return true;
    }

    std::string minWindow(std::string s, std::string t) {
        for (const char &c : t) {
            ori[c]++;
        }

        int l = 0, r = -1,ansl=-1,ns=s.size(),minlen=100001;

        while (r < ns) {
            r++;
            if (ori.find(s[r]) != ori.end()) {
                cnt[s[r]]++;
            }


            while (check() && l <= r) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    ansl = l;
                }

                if (ori.find(s[l]) != ori.end()) {
                    cnt[s[l]]--;
                }
                l++;
            }
        }

        return ansl == -1 ? "" : s.substr(ansl,minlen);
    }
};

int main()
{
    Solution sol;

    std::string s=sol.minWindow("a","a");
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
