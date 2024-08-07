// 19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* np = head;
        std::vector<ListNode*> na;
        int tn = 0,fn=0;
        while (np != nullptr) {
            na.push_back(np);
            tn++;
            np = np->next;
        }
        na.push_back(nullptr);
        fn = tn - n;
        if (fn == 0)
            return na[1];
        na[fn - 1]->next = na[fn + 1];
        return head;
    }
};

int main()
{
    int i = 0;
    std::vector<int> a = { 1, 2 };
    ListNode* be = new ListNode;
    ListNode* np=be;
    for (i = 0; i < a.size()-1; i++) {
        np->val = a[i];
        ListNode* ne = new ListNode;
        np->next = ne;
        np = np->next;
    }
    np->val = a[i];
    np->next = nullptr;

    Solution sol;
    sol.removeNthFromEnd(be, 1);

    while (be != nullptr) {
        std::cout << be->val;
        be = be->next;
    }

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
