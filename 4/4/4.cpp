// 4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>



class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = 0, n2 = 0, fi = 0, ib1 = 0, ib2 = 0, i2 = 0, k = 0,left = 0, right = 0,middle=0,tempn=0,i=0,j=0;
        double m = 0,t1=0,t2=0;
        n1 = nums1.size();
        n2 = nums2.size();
        std::vector<int> temp;


        if (n1 > n2)
        {
            temp = nums1;
            nums1 = nums2;
            nums2 = temp;

            tempn = n1;
            n1 = n2;
            n2 = tempn;

        }

        middle = (n1 + n2 + 1) / 2;
        left = 0;
        right = n1;

        if (n1 == 0)
        {
            if (n2 % 2 == 0)
                m = (double)(nums2[middle] + nums2[middle - 1]) / 2;
            else
                m = (double)nums2[middle - 1];
            return m;
        }

        while (left<right)
        {
            if ((right - left) != 1)
            {
                i = left + (right - left) / 2;
                j = middle - i;

                if (i == 0)
                {
                    if (nums1[i] < nums2[j - 1])
                        left = i;
                    else
                        right = i - 1;
                }
                else
                {
                    if (nums1[i - 1] > nums2[j])
                    {
                        right = i - 1;
                    }
                    else
                    {
                        left = i;
                    }
                }
            }
            else
            {
                i = left;
                j = middle - left;
                if (j == 0)
                    left = right;
                else
                {
                    if (nums1[i] < nums2[j-1])
                        left=right;
                    else
                        right=left;
                }
            }

                

        }
        ////////////////////////////////////////////
        if ((n1 + n2) % 2 == 0)
        {
            if (left == 0&&(middle-left)!=n2)
            {
                if (nums1[left]>nums2[middle-left])
                    m= ((double)(nums2[middle-left] + nums2[middle -left-1])) / 2;
                else
                    m = ((double)(nums1[left] + nums2[middle - left - 1])) / 2;
            }
            if (left == 0 && (middle - left) == n2)
            {
                m = ((double)(nums1[left] + nums2[middle - left - 1])) / 2;
            }
            if (left == n1&&(middle-left)!=0)
            {
                if (nums1[left-1]>nums2[middle-left-1])
                    m= ((double)(nums1[left-1] + nums2[middle - left])) / 2;
                else
                    m = ((double)(nums2[middle-left - 1] + nums2[middle - left])) / 2;
            }
            if (left == n1 && (middle - left) == 0)
            {
                m = ((double)(nums1[left - 1] + nums2[middle - left])) / 2;
            }
            if ((middle - left) == 0&&left!=n1)
            {
                if (nums1[left]>nums2[middle-left])
                    m= ((double)(nums1[left - 1] + nums2[middle - left])) / 2;
                else
                    m = ((double)(nums1[left - 1] + nums1[left])) / 2;
            }
            if ((middle - left) == n2&&left!=0)
            {
                if (nums1[left-1]>nums2[middle-left-1])
                    m= ((double)(nums1[left] + nums2[middle - left - 1])) / 2;
                else
                    m = ((double)(nums1[left] + nums1[left - 1])) / 2;
            }

            if (!((left == 0)||(left == n1)||((middle - left) == 0)||((middle - left) == n2)))
            {
                if (nums1[left - 1] > nums2[middle - left - 1])
                    t1 = nums1[left - 1];
                else
                    t1 = nums2[middle - left - 1];


                if (nums1[left] < nums2[middle - left])
                    t2 = nums1[left];
                else
                    t2 = nums2[middle - left];

                m = (t1 + t2) / 2;
            }

                
        }
        if ((n1 + n2) % 2 != 0)
        {
            if (left == 0)
                m= (double)nums2[middle - left - 1];
            if ((middle - left) == 0)
                m= (double)nums1[left - 1];
            if (!((left == 0) || ((middle - left) == 0)))
            {
                if (nums1[left - 1] > nums2[middle - left - 1])
                    m= (double)nums1[left - 1];
                else
                    m= (double)nums2[middle - left - 1];
            }

        }

        return m;
    }
};



int main()
{
    std::vector<int>a1 = { 1,2};
    std::vector<int>a2 = { 3,4};

    Solution s;
    std::cout<<s.findMedianSortedArrays(a1, a2);
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
