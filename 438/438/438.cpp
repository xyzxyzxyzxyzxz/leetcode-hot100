// 438.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


class Solution {
public:

    std::vector<int> findAnagrams(std::string s, std::string p) {
        int np = p.size(),ns=s.size();

        std::vector<int> res;

        std::unordered_map<char, int> pmap,smap;

        for (int i = 0; i < np; i++) {
            pmap[p[i]]++;
            smap[s[i]]++;
        }

        int i = 0;
        for (i = 0; i < ns - np; i++) {
            if (smap==pmap) {
                res.push_back(i);
            }
            if (smap[s[i]] == 1) {
                smap.erase(s[i]);
            }
            else {
                smap[s[i]]--;
            }
            smap[s[i + np]]++;
        }
        if (smap == pmap) {
            res.push_back(i);
        }

        return res;
    }
};

int main()
{
    Solution sol;

    std::vector<int> res=sol.findAnagrams("cbaebabacd", "abc");

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
