// 3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int cur_len = 1, i = 0, cur_po = 0, max_len = 1, f = 0;
        while (1)
        {
            f = 0;
            i = 0;
            std::cout << std::endl << "po" << cur_po;
            while ((cur_po + i) < (cur_po + cur_len))
            {
                std::cout << "len" << cur_len;
                if (s[cur_po + i] != s[cur_po + cur_len])
                {
                    i++;
                }
                else
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                if ((cur_po + cur_len + 1) >= s.length())
                {
                    if (cur_len >= max_len)
                        max_len = cur_len+1;
                    break;
                }
                cur_len++;
            }
            else
            {
                if (cur_len > max_len)
                {
                    max_len = cur_len;
                }
                cur_len = 1;
                cur_po++;
            }
            if ((cur_po + 1 + max_len) > s.length())
            {
                break;
            }

        }

        return max_len;
    }
};

int main()
{
    std::string s = "aaa";
    Solution so;
    std::cout<<so.lengthOfLongestSubstring(s);
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
