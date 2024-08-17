// 56.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


class Solution {
public:
    static bool CompInte(const std::vector<int>& inte1, const std::vector<int>& inte2) {
        if (inte1[0] < inte2[0]) {
            return true;
        }
        else if (inte1[0] > inte2[0]) {
            return false;
        }
        else {
            if (inte1[1] < inte2[1]) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }

        if (intervals.size() == 1) {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end(), CompInte);
        int cL=intervals[0][0], cR= intervals[0][1], mL= intervals[0][0], mR = 1001;

        bool first=true;

        std::vector<std::vector<int>> res;
        
        

        int left0 = intervals[0][0];
        

        auto it = intervals.begin();
        auto itn = it + 1;

        for (; itn != intervals.end(); it++,itn++) {
            if ((*itn)[0] == left0) {
                continue;
            }
            left0 = (*itn)[0];
            
            if ((*it)[0] <= mR) {
                if (first) {
                    mR = (*it)[1];
                }
                mR = std::max((*it)[1],mR);
            }
            else {
                res.push_back({ mL,mR });
                mL = (*it)[0];
                mR = (*it)[1];
            }
            first = false;
        }

        if (first) {
            return { *(intervals.end() - 1) };
        }

        if ((*it)[0] <= mR) {
            mR = std::max(mR,(*it)[1]);
            res.push_back({mL,mR});
        }
        else {
            res.push_back({ mL,mR });
            res.push_back({(*it)[0],(*it)[1]});
        }


        return res;
    }
};

int main()
{
    std::vector<std::vector<int>> intervals = { {2,3},{4,5},{6,7},{8,9},{1,10} };
    std::vector<std::vector<int>> res;

    Solution sol;

    res = sol.merge(intervals);

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
