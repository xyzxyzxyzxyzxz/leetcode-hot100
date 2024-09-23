// 399.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>


class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        int nvars = 0;
        std::unordered_map<std::string, int> vari;

        int n = equations.size();
        for (int i = 0; i < n; i++) {
            if (vari.find(equations[i][0]) == vari.end()) {
                vari[equations[i][0]] = nvars++;
            }
            if (vari.find(equations[i][1]) == vari.end()) {
                vari[equations[i][1]] = nvars++;
            }
        }

        std::vector<std::vector<std::pair<int, double>>> edges(nvars);

        for (int i = 0; i < n; i++) {
            int va = vari[equations[i][0]], vb = vari[equations[i][1]];
            edges[va].push_back(std::make_pair(vb, values[i]));
            edges[vb].push_back(std::make_pair(va, 1 / values[i]));
        }

        std::vector<double> res;

        for (const auto& q : queries) {
            double result = -1;
            if (vari.find(q[0]) != vari.end() && vari.find(q[1]) != vari.end()) {
                int ia = vari[q[0]], ib = vari[q[1]];
                if (ia == ib) {
                    result = 1;
                }
                else {
                    std::queue<int> points;
                    points.push(ia);
                    std::vector<double> ratios(nvars, -1);
                    ratios[ia] = 1;

                    while (!points.empty() && ratios[ib] == -1) {
                        int x = points.front();
                        points.pop();

                        for (const std::pair<int,double> y_val : edges[x]) {
                            if (ratios[y_val.first] == -1) {
                                ratios[y_val.first] = ratios[x] * y_val.second;
                                points.push(y_val.first);
                            }
                        }
                    }

                    result = ratios[ib];
                }
            }
            res.push_back(result);
        }

        return res;
    }
};

int main()
{
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
