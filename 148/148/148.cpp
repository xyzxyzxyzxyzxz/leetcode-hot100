// 148.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (!head) {
            return head;
        }

        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head, * slow = head;

        while (fast != tail) {
            fast = fast->next;
            slow = slow->next;
            if (fast!=tail) {
                fast = fast->next;
            }
        }

        ListNode* mid = slow;

        return merge(sortList(head,mid),sortList(mid,tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode();
        ListNode* temp = dummyHead, * temp1 = head1, * temp2 = head2;

        while (temp1 && temp2) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if (temp1) {
            temp->next = temp1;
        }
        else if (temp2) {
            temp->next = temp2;
        }

        return dummyHead->next;
    }
};

int main()
{
    int i = 0;
    std::vector<int> a1 = { 4,2,1,3 };
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

    Solution sol;
    sol.sortList(be1);

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
