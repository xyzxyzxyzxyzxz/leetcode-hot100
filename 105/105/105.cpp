﻿// 105.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>



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
    std::unordered_map<int, int> index;

    TreeNode* buildTreepi(const std::vector<int>& preorder, const std::vector<int>& inorder, int pleft, int pright, int ileft, int iright) {
        if (pleft > pright) {
            return nullptr;
        }
        //根节点
        TreeNode* root = new TreeNode(preorder[pleft]);

        int leftlen = index[preorder[pleft]] - ileft;

        root->left = buildTreepi(preorder, inorder, pleft + 1, pleft + leftlen, ileft, ileft + leftlen - 1);

        root->right = buildTreepi(preorder, inorder, pleft + leftlen + 1, pright, ileft + leftlen + 1, iright);

        return root;
    }

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        return buildTreepi(preorder, inorder, 0, n - 1, 0, n - 1);
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
