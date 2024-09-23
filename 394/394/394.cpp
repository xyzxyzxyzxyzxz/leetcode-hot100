// 394.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    std::stack<int> bp;

    std::string decrbra(std::string& s, int beg, int end) {
        int nbeg = beg,nend=beg;
        while (s[nbeg] >= 'a' && s[nbeg] <= 'z'&&nbeg<=end) {
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

        int nextbb = nend + 1, nextbe = end;

        while (s[nextbe] != ']') {
            nextbe--;
        }


        std::string resp = decrbra(s, nextbb + 1, nextbe - 1);
        std::string res;

        for (int i = 0; i < repe; i++) {
            res += resp;
        }
        res = s.substr(beg, nbeg - beg) + res + s.substr(nextbe + 1, end - nextbe);

        return res;

        



    }



    std::string decodeString(std::string s) {

        bool ispush = false;
        int bbeg=0;
        std::string res;
        for (int i = 0; i < s.size();i++) {
            if (s[i] == '[') {
                bp.push(i);
                ispush = true;
            }
            if (s[i] == ']') {
                bp.pop();
            }
            if (bp.empty() && ispush) {
                res = res + decrbra(s, bbeg, i);
                bbeg = i + 1;
                ispush = false;
            }
        }

        res = res + s.substr(bbeg);

        return res;
    }
};


int main()
{
    std::string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";

    Solution sol;
    sol.decodeString(s);

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
