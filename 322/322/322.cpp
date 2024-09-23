// 322.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    
    int n;

    std::vector<int> allmetnum;

    int allmeth(std::vector<int>& coins, int ream) {
        if (ream == 0) {
            return 0;
        }
        
        if (ream < 0) {
            return -1;
        }
        if (allmetnum[ream] != 0) {
            return allmetnum[ream];
        }
        int minnext = 0,minnow=INT_MAX;

        for (int i = 0; i < n; i++) {
            minnext=allmeth(coins, ream - coins[i]);
            if (minnext != -1) {
                if (minnext + 1 < minnow) {
                    minnow = minnext + 1;
                }
            }
        }
        allmetnum[ream] = minnow == INT_MAX ? -1 : minnow;
        return allmetnum[ream];
    }

    int coinChange(std::vector<int>& coins, int amount) {
        
        n = coins.size();
        allmetnum.resize(amount + 1);
        return allmeth(coins, amount);
    }
};

int main()
{
    std::vector<int> coins = { 2 };

    Solution sol;
    sol.coinChange(coins, 3);
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
