#include <bits/stdc++.h>
using namespace std;

// 2781. Length of the Longest Valid Substring [H]
// LeetCode length-of-the-longest-valid-substring

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i ++) children[i] = nullptr;
    }

    TrieNode* get (char c) {
        return children[c - 'a'];
    }
    void set(char c) {
        children[c - 'a'] = new TrieNode();
    }
};
struct Trie {
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->get(c)) node->set(c);
            node = node->get(c);
        }
        node->isEnd = true;
    }

    // 在Trie树中搜索word的子串[left, right]
    bool search(string& word, int left, int right) {
        TrieNode* node = root;
        for(int i = left; i <= right; i++) {
            // 如果当前字符不在Trie树中，返回false
            if(!node->get(word[i])) return false;
            // 移动到子节点
            node = node->get(word[i]);
            // 如果遇到一个单词结尾，返回true
            if(node->isEnd) return true;
        }
        // 遍历完整个子串但没有遇到单词结尾
        return false;
    }
};
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int ans = 0;        // 存储最终结果（最长有效子串长度）
        int n = word.size(); // 输入字符串的长度
        int left = n - 1, right = n - 1; // 滑动窗口的左右指针，初始化为字符串末尾
        
        Trie trie; // 创建Trie树
        
        // 将所有禁止词插入Trie树
        for(string f : forbidden) trie.insert(f);
        
        // 主循环：从右向左移动左指针
        while(left >= 0) {
            // 调整右指针：如果当前子串包含禁止词，则缩小窗口
            while(left <= right && trie.search(word, left, right)) {
                right -= 1;
            }
            // 更新最大长度
            ans = max(ans, right - left + 1);
            // 移动左指针
            left -= 1;
        }
        
        return ans;
    }
};