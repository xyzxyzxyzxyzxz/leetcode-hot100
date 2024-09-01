// 207.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>


class Solution {
private:
    std::vector<std::vector<int>> edges;
    std::vector<int> visited;
    bool valid;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses,0);

        valid = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && valid) {
                dfs(i);
            }
        }

        return valid;
    }
};

int main()
{
    std::vector<std::vector<int>> pre = { {1,0},{0,1} };
    Solution sol;
    bool res = sol.canFinish(2, pre);
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
