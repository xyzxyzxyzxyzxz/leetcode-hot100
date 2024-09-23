// 297.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <list>


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {

public:
    void travtree_seri(TreeNode* root, std::string& str) {
        if (!root) {
            str += "None,";
            return;
        }
        else {
            str += std::to_string(root->val) + ",";
            travtree_seri(root->left, str);
            travtree_seri(root->right, str);
        }
    }

    TreeNode* travtree_deseri(std::list<std::string> &vallist) {
        if (vallist.front() == "None") {
            vallist.erase(vallist.begin());
            return nullptr;
        }

        TreeNode* node = new TreeNode(std::stoi(vallist.front()));
        vallist.erase(vallist.begin());
        node->left = travtree_deseri(vallist);
        node->right = travtree_deseri(vallist);

        return node;
    }

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string seri;
        travtree_seri(root, seri);
        return seri;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::list<std::string> vallist;
        std::string str;
        for (char c : data) {
            if (c == ',') {
                vallist.push_back(str);
                str.clear();
            }
            else {
                str += c;
            }
        }

        return travtree_deseri(vallist);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



int main()
{
    TreeNode* root =new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec cod;
    std::string seri = cod.serialize(root);
    TreeNode* root1 = cod.deserialize(seri);

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
