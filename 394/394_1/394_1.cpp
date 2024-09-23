// 394_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>



class Solution {
public:
    std::unordered_map<int, int> bp;
    std::stack<int> bstk;
    int n;

    std::string resos(std::string& s, int beg, int end) {
        int nbeg = beg, nend;

        if (s[beg] == ']') {
            return "";
        }

        while ((s[nbeg] >= 'a' && s[nbeg] <= 'z') && nbeg <= end) {
            nbeg++;
        }
        nend = nbeg;

        if (nbeg > end) {
            return s.substr(beg, end - beg + 1);
        }
        while (s[nend] >= '0' && s[nend] <= '9') {
            nend++;
        }
        nend--;

        int repe = std::stoi(s.substr(nbeg, nend - nbeg + 1));

        int bend = bp[nend + 1];

        std::string resp = resos(s, nend + 2, bend );
        std::string res;
        res = s.substr(beg, nbeg - beg);
        for (int i = 0; i < repe; i++) {
            res += resp;
        }

        res += resos(s, bend + 1, end - 1);

        return res;
    }

    std::string decodeString(std::string s) {
        n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                bstk.push(i);
            }
            else if (s[i] == ']') {
                bp[bstk.top()] = i;
                bstk.pop();
            }
        }
        std::string res = resos(s, 0, n - 1);

        return res;
    }
};

int main()
{
    std::string s = "2[abc]3[cd]ef";
    Solution sol;
    std::string res = sol.decodeString(s);

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
