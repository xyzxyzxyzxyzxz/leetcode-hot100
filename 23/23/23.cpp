// 23.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>



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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int len = lists.size(),min_ind=0,cur_val;
        bool all_null = false, fir = false;

        ListNode* be = new ListNode;
        ListNode* np = be;

        if (len == 0) {
            return nullptr;
        }

        while (!all_null) {
            all_null = true;
            fir = false;
            for (int i = 0; i < len; i++) {
                
                if (lists[i] == nullptr) {
                    continue;
                }
                else{
                    if (all_null) {
                        all_null = false;
                        cur_val = lists[i]->val;
                        min_ind = i;
                    }
                    else {
                        if (lists[i]->val < cur_val) {
                            min_ind = i;
                            cur_val = lists[i]->val;
                        }
                    }
                }
                
                
            }
            if (!all_null) {
                np->next = lists[min_ind];
                np = np->next;
                lists[min_ind] = lists[min_ind]->next;
            }

        }
        np->next = nullptr;
        return be->next;

    }
};

int main()
{
    std::vector<ListNode*> ln;

    int i = 0;
    std::vector<int> a = { 1,4,5 };
    ListNode* be = new ListNode;
    ListNode* np = be;
    for (i = 0; i < a.size() - 1; i++) {
        np->val = a[i];
        ListNode* ne = new ListNode;
        np->next = ne;
        np = np->next;
    }
    np->val = a[i];
    np->next = nullptr;

    ln.push_back(be);

    i = 0;
    a = { 1,3,4 };
    be = new ListNode;
    np = be;
    for (i = 0; i < a.size() - 1; i++) {
        np->val = a[i];
        ListNode* ne = new ListNode;
        np->next = ne;
        np = np->next;
    }
    np->val = a[i];
    np->next = nullptr;

    ln.push_back(be);

    i = 0;
    a = { 2,6};
    be = new ListNode;
    np = be;
    for (i = 0; i < a.size() - 1; i++) {
        np->val = a[i];
        ListNode* ne = new ListNode;
        np->next = ne;
        np = np->next;
    }
    np->val = a[i];
    np->next = nullptr;

    ln.push_back(be);

    Solution sol;

    ListNode* res;

    res=sol.mergeKLists(ln);




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
