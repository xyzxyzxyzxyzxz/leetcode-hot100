// 69_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>





class Solution {

public:


    unsigned char bit_width(unsigned long long x) {
        return x == 0 ? 1 : 64 - __builtin_clzll(x);
    }

    // implementation for all unsigned integer types
    unsigned mySqrt(const unsigned n) {
        unsigned char shift = bit_width(n);
        shift += shift & 1; // round up to next multiple of 2

        unsigned result = 0;

        do {
            shift -= 2;
            result <<= 1; // leftshift the result to make the next guess
            result |= 1;  // guess that the next bit is 1
            result ^= result * result > (n >> shift); // revert if guess too high
        } while (shift != 0);

        return result;
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
