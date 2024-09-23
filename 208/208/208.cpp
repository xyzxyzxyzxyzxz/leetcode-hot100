// 208.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

class Trie {
private:
    std::vector<Trie*> children;
    bool isEnd;

    Trie* prefixSearch(std::string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (!node->children[c - 'a']) {
                return nullptr;
            }
            node = node->children[c - 'a'];
        }

        return node;
    }

public:
    Trie():children(26),isEnd(false) {

    }

    void insert(std::string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new Trie;
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(std::string word) {
        Trie* node = prefixSearch(word);
        if (!node) {
            return false;
        }
        else {
            return node->isEnd;
        }
    }

    bool startsWith(std::string prefix) {
        Trie* node = prefixSearch(prefix);
        if (node) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

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
