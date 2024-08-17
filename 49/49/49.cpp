// 49.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        int strsn = strs.size();
        bool hvempt = false;
        std::string str0,strc;
        std::vector<int> perm;

        std::vector<std::vector<std::string>> res;

        std::vector<std::string> asol;

        for (auto it =strs.begin() ; it!=strs.end();) {
            if (*it == "") {
                hvempt = true;
                strs.erase(it);
                asol.push_back("");
            }
            else {
                it++;
            }
        }

        if (hvempt) {
            res.push_back(asol);
        }

        while (strs.size() != 0) {
            asol.clear();
            str0 = strs[0];
            int str0n = str0.size();
            perm.clear();
            for (int i = 1; i <= str0n; i++) {
                perm.push_back(i);
            }
            strc = "";
//            do {
//
//            }while (std::next_permutation(perm.begin))
            do {
                strc.clear();
                for (int i = 0; i < perm.size(); i++) {
                    strc.push_back(str0[perm[i]-1]);
                }
                strsn = strs.size();
                strs.erase(std::remove(strs.begin(), strs.end(), strc), strs.end());

                if (strsn != strs.size()) {
                    for (int i = 0; i < strsn - strs.size(); i++) {
                        asol.push_back(strc);
                    }
                    
                }

            } while (std::next_permutation(perm.begin(), perm.end()));

            res.push_back(asol);
        }

        return res;
    }
};

int main()
{
    std::vector<std::string> strs = { "eat","tea","tan","ate","nat","bat" };

    Solution sol;
    std::vector<std::vector<std::string>> res;
    res=sol.groupAnagrams(strs);

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
