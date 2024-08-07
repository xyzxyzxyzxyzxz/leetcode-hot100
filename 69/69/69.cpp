// 69.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>


class Solution {

public:
    double s2 = 1.41421356237309504880168872420969807856967187537694807317667973799;
    static unsigned long upper_power_of_two(unsigned long v)
    {
        v--;
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        v++;
        return v;

    }
    int mySqrt(int x) {
        unsigned long n3 = 0;
        double re=1,p=0;
        unsigned long pow = 0;

        if (x == 0)
            return 0;

        n3=Solution::upper_power_of_two(x);
        p = ((double)x) / n3 - 1;
        
        pow = Solution::getThePowerOfTwo(n3);
        for (int i = 1; i <= pow / 2 + 2; i++)
        {
            re = re + Solution::coef(i,p);
         }

        if (pow % 2 == 0)
        {
            re = re * (1 << (int)(pow / 2));
        }
        else
        {
            re = re * (1 << (int)(pow / 2)) * Solution::s2;
        }
        return (int)re;

    }

    static double coef(int n,double x)
    {
        double re = 1;
        for (int i = 1; i <= n; i++)
        {
            re = re * (0.5 - i + 1) / (double)i * x;
        }
        return re;
    }

    static int getThePowerOfTwo(unsigned int value) {
        static constexpr int twos[] = {
            1 << 0,  1 << 1,  1 << 2,  1 << 3,  1 << 4,  1 << 5,  1 << 6,  1 << 7,
            1 << 8,  1 << 9,  1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15,
            1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 1 << 23,
            1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30, 1 << 31
        };

        return std::lower_bound(std::begin(twos), std::end(twos), value) - std::begin(twos);
    }
};




int main()
{
    Solution sol;
    
    std::cout << sol.mySqrt(4);
 
    
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
