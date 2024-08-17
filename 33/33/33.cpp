// 33.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>


class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int fn = 0, n = nums.size(), fleft = 0, fright = nums.size() - 1, fm = 0, n0 = nums[0],roti=-1,nr=0;

        if (n == 1) {
            if (target == nums[0])
                return 0;
            else
                return -1;
        }

        if (n == 2) {
            if (target == nums[0])
                return 0;
            else if (target == nums[1])
                return 1;
            else
                return -1;
        }

        if (nums[n - 1] > nums[0]) {
            roti = 0;
        }
        if (nums[n - 1] < nums[0] && nums[n - 1] < nums[n - 2]) {
            roti = n - 1;
        }


        if (roti == -1) {
            while (1) {
                fm = fleft + (fright - fleft) / 2;
                if (nums[fm] < n0) {
                    fright = fm;
                    break;
                }
                fleft = fm + 1;

            }//旋转点在fleft和fright之间





            if (nums[fm] < nums[fm - 1] && nums[fm] < nums[fm + 1]) {
                roti = fm;
            }
            else if(fleft != 0){
                if (nums[fleft] < nums[fleft - 1] && nums[fleft] < nums[fleft + 1]) {
                    roti = fleft;
                }
            }
            

            if (roti==-1) {
                nr = nums[fright];
                while (1) {
                    fm = fleft + (fright - fleft) / 2;

                    if (fm != 0) {
                        if (nums[fm] < nums[fm - 1] && nums[fm] < nums[fm + 1]) {
                            roti = fm;
                            break;
                        }
                    }


                    if (nums[fm] < nr) {
                        fright = fm - 1;
                    }
                    else {
                        fleft = fm + 1;
                    }
                }
            }
        }

        if (target == nums[n - 1]) {
            return n - 1;
        }
        else if (target > nums[n - 1]&&roti!=0) {
            fleft = 0;
            fright = roti - 1;
        }
        else if (target < nums[n - 1] && roti != 0) {
            fleft = roti;
            fright = n - 1;
        }
        else if (roti == 1) {
            fleft = 0;
            fright = n - 1;
        }

        while (fleft <= fright) {
            int mid = fleft + (fright - fleft) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                fleft = mid + 1;

            }
            else if (nums[mid] > target) {
                fright = mid - 1;
            }
        }

        return -1;

    }
};

int main()
{
    std::vector<int> nums = { 57,58,59,62,63,66,68,72,73,74,75,76,77,78,80,81,86,95,96,97,98,100,101,102,103,110,119,120,121,123,125,126,127,132,136,144,145,148,149,151,152,160,161,163,166,168,169,170,173,174,175,178,182,188,189,192,193,196,198,199,200,201,202,212,218,219,220,224,225,229,231,232,234,237,238,242,248,249,250,252,253,254,255,257,260,266,268,270,273,276,280,281,283,288,290,291,292,294,295,298,299,4,10,13,15,16,17,18,20,22,25,26,27,30,31,34,38,39,40,47,53,54 };

    Solution sol;
    std::cout<<sol.search(nums, 30);
    
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
