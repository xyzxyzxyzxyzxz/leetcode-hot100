﻿// 617.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* travtree(TreeNode* node1, TreeNode* node2,TreeNode* nnode) {
        TreeNode *nnn;
        if (!node1 && !node2) {
            nnode = nullptr;
            return nullptr;
        }
        int cur_val=0;
        if (!node1) {
            
            cur_val = node2->val;
            nnode = new TreeNode(cur_val);
            nnode->left=travtree(nullptr, node2->left, nnode->left);
            nnode->right=travtree(nullptr, node2->right, nnode->right);
        }
        else if (!node2) {
            
            cur_val = node1->val;
            nnode = new TreeNode(cur_val);
            nnode->left=travtree(node1->left, nullptr, nnode->left);
            nnode->right=travtree(node1->right, nullptr, nnode->right);
        }
        else {
            cur_val = node1->val + node2->val;
            nnode = new TreeNode(cur_val);
            nnode->left=travtree(node1->left, node2->left, nnode->left);
            nnode->right=travtree(node1->right, node2->right, nnode->right);
        }




        return nnode;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* nroot=travtree(root1, root2, nullptr);
        return nroot;
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
