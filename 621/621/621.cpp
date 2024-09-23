// 621.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, std::pair<int, int>> taskmp;

        for (char c : tasks) {
            taskmp[c].first = 1;
            taskmp[c].second++;
        }


        int time = 1;
        while(!taskmp.empty()) {
            auto it = taskmp.begin();
            int maxn = 0, mintime = INT_MAX;
            char taskc,mintaskc;
            while (it != taskmp.end()) {
                if (it->second.first <= time) {
                    if (it->second.second > maxn) {
                        maxn = it->second.second;
                        taskc = it->first;
                    }
                }
                if (it->second.first < mintime) {
                    mintime = it->second.first;
                    mintaskc = it->first;
                }
                it++;
            }

            if (maxn == 0) {
                time = mintime;
                continue;
            }
            taskmp[taskc].second--;
            taskmp[taskc].first = time + n + 1;
            if (taskmp[taskc].second == 0) {
                taskmp.erase(taskc);
            }
            time++;
        }

        return time-1;
    }
};

int main()
{
    std::vector<char> tasks = { 'A','A','A','B','B','B'};
    Solution sol;
    int res=sol.leastInterval(tasks, 2);
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
