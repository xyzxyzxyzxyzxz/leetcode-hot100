// 101.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    bool travtree(TreeNode* root1, TreeNode* root2) {
        bool res = false;
        if ((!root1)&&root2) {
            res= false;
        }

        if (!root1 && !root2) {
            res= true;
        }

        if (root1 && root2) {
            res= (root1->val==root2->val) && travtree(root1->left, root2->right) && travtree(root1->right, root2->left);
        }
        return res;
        
    }
    bool isSymmetric(TreeNode* root) {
        return travtree(root->left, root->right);
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
