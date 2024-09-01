// 146.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>



struct DLinkedNode
{
    int key, value;
    DLinkedNode* prev, * next;

    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};


class LRUCache {
private:
    int size;
    int capacity;
    DLinkedNode* head, * tail;
    std::unordered_map<int, DLinkedNode*> cache;

public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        else {
            DLinkedNode* node = cache[key];

            moveToHead(node);
            return node->value;

        }
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;

            head->next->prev = node;
            node->next = head->next;
            head->next = node;
            node->prev = head;

            size++;

            if (size > capacity) {
                cache.erase(tail->prev->key);
                DLinkedNode* removed = tail->prev;
                removed->prev->next = tail;
                tail->prev = removed->prev;

                delete removed;
            }
        }
    }

    void moveToHead(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        head->next->prev = node;
        node->next = head->next;

        head->next = node;
        node->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
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
