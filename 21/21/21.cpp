// 21.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>



struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* np1, * np2, * np, * st;
        np1 = list1;
        np2 = list2;

        np = new ListNode;
        st = np;

        while (np1 != nullptr && np2 != nullptr) {
            if (np1->val < np2->val) {
                np->next = np1;
                np1 = np1->next;
                np = np->next;
            }
            else {
                np->next = np2;
                np2 = np2->next;
                np = np->next;
            }
        }

        if (np1 == nullptr) {
            while (np2 != nullptr) {
                np->next = np2;
                np2 = np2->next;
                np = np->next;
            }
        }
        else {
            while (np1 != nullptr) {
                np->next = np1;
                np1 = np1->next;
                np = np->next;
            }
        }
        np->next = nullptr;

        return st->next;
    }
};


int main()
{
    int i = 0;
    std::vector<int> a1 = { 1, 2 };
    ListNode* be1 = new ListNode;
    ListNode* np1 = be1;
    for (i = 0; i < a1.size() - 1; i++) {
        np1->val = a1[i];
        ListNode* ne1 = new ListNode;
        np1->next = ne1;
        np1 = np1->next;
    }
    np1->val = a1[i];
    np1->next = nullptr;


    i = 0;
    std::vector<int> a2 = { 1, 2 };
    ListNode* be2 = new ListNode;
    ListNode* np2 = be2;
    for (i = 0; i < a2.size() - 1; i++) {
        np2->val = a2[i];
        ListNode* ne2 = new ListNode;
        np2->next = ne2;
        np2 = np2->next;
    }
    np2->val = a2[i];
    np2->next = nullptr;

    ListNode* be3;

    Solution sol;
    be3 = sol.mergeTwoLists(be1, be2);
    std::cout << " ";

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
