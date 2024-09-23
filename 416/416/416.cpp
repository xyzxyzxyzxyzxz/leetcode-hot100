// 416.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <numeric>


class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return false;
        }

        int sum = std::accumulate(nums.begin(), nums.end(),0);
        if (sum & 1) {
            return false;
        }
        int maxelem = *std::max_element(nums.begin(), nums.end());
        if (maxelem > sum / 2) {
            return false;
        }
        
        int targ = sum / 2;
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(targ + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 0; j <= targ; j++) {
                if (j > num) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
                }
            }
        }

        return dp[n - 1][targ];
    }
};

int main()
{
    std::vector<int> nums = { 1,5,11,5 };

    Solution sol;

    bool res = sol.canPartition(nums);
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
