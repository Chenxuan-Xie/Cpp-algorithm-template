#include <bits/stdc++.h>
using namespace std;

// 字典树（Trie）模板
class Trie {
private:
    bool isEnd; // 标识是否为某个字符串的结尾
    vector<Trie*> next; // 指向子节点的指针数组，通常大小为26（只包含小写字母）

public:
    // 1. 构造函数
    Trie() {
        isEnd = false; // 初始时不是任何字符串的结尾
        next.assign(26, nullptr); // 初始化26个子节点，均为空
    }

    // 2. 析构函数（释放内存，避免内存泄漏）
    ~Trie() {
        for (auto child : next) {
            if (child != nullptr) {
                delete child;
            }
        }
    }

    // 3. insert方法（插入字符串）
    // 向字典树中插入一个字符串 word
    void insert(string word) {
        Trie* node = this; // 从根节点开始
        for (char c : word) { // 遍历字符串的每一个字符
            int index = c - 'a'; // 计算字符在数组中的索引（0-25）
            if (node->next[index] == nullptr) { // 如果该字符对应的子节点不存在
                node->next[index] = new Trie(); // 创建新的子节点
            }
            node = node->next[index]; // 移动到子节点
        }
        node->isEnd = true; // 字符串遍历结束，标记当前节点为字符串结尾
    }

    // 4. search方法（查找完整的字符串）
    // 判断字典树中是否存在字符串 word
    bool search(string word) {
        Trie* node = this; // 从根节点开始
        for (char c : word) { // 遍历字符串的每一个字符
            int index = c - 'a'; // 计算字符在数组中的索引
            if (node->next[index] == nullptr) { // 如果子节点不存在，说明不存在该字符串
                return false;
            }
            node = node->next[index]; // 移动到子节点
        }
        return node->isEnd; // 字符串遍历结束，判断当前节点是否为某个字符串的结尾
    }

    // 5. startsWith方法（查找前缀）
    // 判断字典树中是否存在以 prefix 为前缀的字符串
    bool startsWith(string prefix) {
        Trie* node = this; // 从根节点开始
        for (char c : prefix) { // 遍历前缀字符串的每一个字符
            int index = c - 'a'; // 计算字符在数组中的索引
            if (node->next[index] == nullptr) { // 如果子节点不存在，说明不存在该前缀
                return false;
            }
            node = node->next[index]; // 移动到子节点
        }
        return true; // 前缀遍历结束且都存在，说明存在该前缀
    }
};
