// 5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>


class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int l = 0, i = 0, j = 0, cur_len = 1, in_be = 0, f = 0, max_len = 1,max_be=0;
        std::string max;

        l = s.length();
        while (in_be+max_len<=l)
        {
            cur_len = max_len;
            while (in_be + cur_len <= l)
            {
                f = 0;
                i = in_be;
                j = in_be + cur_len-1;
                while (i < j)
                {
                    if (s[i] == s[j])
                    {
                        i++;
                        j--;
                    }
                    else
                    {
                        f = 1;
                        break;
                    }
                }
                if (f == 0)
                {
                    max_be = in_be;
                    max_len = cur_len;
                    cur_len++;

                }
                else
                {
                    cur_len++;

                }
            }

            in_be++;

        }
        max.assign(s, max_be, max_len);
        return max;
    }
};













int main()
{
    Solution sol;
    std::string s = "cbbd",max;

    max = sol.longestPalindrome(s);

    std::cout << max;
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
