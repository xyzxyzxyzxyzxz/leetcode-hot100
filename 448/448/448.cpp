﻿// 448.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n;i++) {
            if (nums[nums[i]%(n+1) - 1] <= n + 1) {
                nums[nums[i]%(n+1) - 1] += n + 1;
            }
        }
        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n+1) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

int main()
{
    std::vector<int> nums = { 4,3,2,7,8,2,3,1 };

    Solution sol;
    std::vector<int> res=sol.findDisappearedNumbers(nums);
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
