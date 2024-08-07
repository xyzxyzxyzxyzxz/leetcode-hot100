// 10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>



class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        std::vector<int> pos_s,pos_s_s;
        bool f = true, f1 = true, ret = false,in=true;
        int ss = 0,ss1=0,sp=0,ep=0,inp=0;

        pos_s.push_back(-1);
        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == '*')
                pos_s.push_back(i);
        }
        while (1)
        {
            sp = pos_s[inp] + 1;
            ep = pos_s[inp + 1] - 1;

            ss = ss1;
            while (1)
            {

                f = noSMatch(ss, s, p, sp, ep);
                if (f == true)
                {
                    break;
                }
                else
                {
                    ss++;
                    f = false;
                }
                if (ss + ep - sp > s.length())
                {
                    break;
                }
            }
            if (f == true)
            {
                inp++;
                pos_s_s.push_back(ss1);
                ss1 = ss1 + ep - sp + 1;
            }
            else
            {
                ss1++;
            }
            if (inp > pos_s.size())
            {
                ret = true;
                break;
            }
            if (ss1 + ep - sp > s.length())
            {
                break;
            }
            
        }

        pos_s.push_back(p.length()-1);
        pos_s_s.push_back(s.length());
        if (ret == true)
        {
            for (int i = 0; i < pos_s_s.size()-1; i++)
            {
                for (int j = pos_s_s[i] + pos_s[i + 1] - pos_s[i]; j < pos_s_s[i + 1]; j++)
                {
                    if (s[j] == p[pos_s[i + 1] - 1] || (p[pos_s[i + 1] - 1] == '.'))
                        continue;
                    else
                    {
                        in = false;
                        break;
                    }
                }
                if (in == false)
                    break;
                    
            }

        }

        
        return ret&&in;
    }
    bool noSMatch(int ss, std::string s, std::string p, int sp, int ep)
    {
        bool f = true;
        for (int i = sp; i <= ep; i++)
        {
            if (s[ss] == p[i]||p[i]=='.')
            {
                ss++;
            }
            else
            {
                f = false;
                break;
            }
        }
        return f;
    }
};




int main()
{
    Solution sol;
    std::string s, p;
    s = "aaa";
    p = "a*a";

    std::cout<<sol.isMatch(s, p);

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
