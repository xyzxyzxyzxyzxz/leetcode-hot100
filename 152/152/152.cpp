// 152.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::vector<long> maxF(nums.size()), minF(nums.size());

        minF[0] = maxF[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxF[i] = std::max(maxF[i - 1] * nums[i], std::max(minF[i - 1] * nums[i], (long)nums[i]));
            minF[i] = std::min(maxF[i - 1] * nums[i], std::min(minF[i - 1] * nums[i], (long)nums[i]));

        }

        return *std::max_element(maxF.begin(), maxF.end());
    }
};

int main()
{
    std::vector<int> v1 = { 2,3,-2,4 };

    Solution sol;
    int res=sol.maxProduct(v1);
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
