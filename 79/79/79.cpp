// 79.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>


class Solution {
public:
    std::vector<std::vector<bool>> *visited;

    std::vector<std::vector<int>> directions = { {0,1},{0,-1},{1,0},{-1,0} };

    bool check(const std::vector<std::vector<char>>& board, int i, int j,const std::string &s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        }
        else if (k == s.size() - 1) {
            return true;
        }

        (*visited)[i][j] = true;

        for (int dir = 0; dir < 4; dir++) {
            int newi = i + directions[dir][0], newj = j + directions[dir][1];
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!((*visited)[newi][newj])) {
                    bool flag = check(board,newi,newj,s,k+1);

                    if (flag) {
                        return true;
                        break;
                    }
                }
            }
        }

        (*visited)[i][j] = false;
        return false;
    }

    bool exist(std::vector<std::vector<char>>&board, std::string word) {
        visited = new std::vector<std::vector<bool>>(board.size(), std::vector<bool>(board[0].size(),false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                bool res = check(board, i, j, word, 0);
                if (res) {
                    return true;
                }
            }
        }

        return false;
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
