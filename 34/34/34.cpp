// 34.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>


class Solution {
public:
    int biSearch(std::vector<int>& nums, int target, bool bequal) {
        int left = 0, right = nums.size() - 1,mid=-1,ans=nums.size();

        if (nums.size() == 0) {
            return -1;
        }

        if (nums[nums.size() - 1] == target && !bequal) {
            return nums.size();
        }

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > target||(bequal&&nums[mid]>=target)) {
                
                right = mid-1;
                ans = right;
               
            }
            else {
                left = mid+1;
            }
        }

        if (bequal) {
            return ans;
        }
        else {
            return ans + 1;
        }
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int tl = -1, tr = -1;

        tr = biSearch(nums, target, false) - 1;
        tl = biSearch(nums, target, true)+1;
        

        if (tl >= 0&&tl<nums.size() && tr < nums.size()&&tr>=0) {
            if (nums[tl] == target && nums[tr] == target) {
                return std::vector<int>{ tl,tr };
            }
        }
            return std::vector<int>{-1, -1};
    }
};

int main()
{
    std::vector<int> nums = { 2,2 },r;

    Solution sol;
    r=sol.searchRange(nums, 2);

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
