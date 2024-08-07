// 2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r = new ListNode(), * begin;
        int qu = 0, re = 0, t = 0, l1v = 0, l2v = 0, s = 0;

        begin = r;
        while (1)
        {

            if (l1 == nullptr)
                l1v = 0;
            else
                l1v = l1->val;
            if (l2 == nullptr)
                l2v = 0;
            else
                l2v = l2->val;

            t = (l1v + l2v);
            std::cout << l1v;
            s = t % 10 + qu;

            if (s == 10)
                r->val = 0;
            else
                r->val = s;



            if (s == 10)
                qu = t / 10 + 1;
            else
                qu = t / 10;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
            if (l1 != nullptr || l2 != nullptr || qu != 0)
            {
                r->next = new ListNode();
                r = r->next;
            }
            else
                break;
        }




        return begin;
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
