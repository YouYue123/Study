#include <bits/stdc++.h>
using namespace std;

// 1268. Search Suggestions System [M]
// LeetCode search-suggestions-system

struct TrieNode {
    bool isEnded;
    TrieNode* children[26];
    TrieNode(): isEnded(false) {
        for(int i = 0; i < 26; i ++) children[i] = nullptr;
    }
    TrieNode* get(char c) {
        return children[c - 'a'];
    }
    void put(char c) {
        children[c - 'a'] = new TrieNode();
    }
};
struct Trie {
    TrieNode* root;
    Trie () {
        root = new TrieNode();
    }
    void put (string word) {
        auto* node = root;
        for(char c : word) {
            if(!node->get(c)) node->put(c);
            node = node->get(c);
        }
        node->isEnded = true;
    }
    vector<string> search(string word) {
        auto* node = root;
        vector<string> ans;
        for(char c : word) {
            node = node->get(c);
            if(!node) return ans;
        }
        dfs(node, ans, word);
        return ans;
    }
    void dfs(TrieNode* node, vector<string>& ans, string& val) {
        if(!node) return;
        if(ans.size() == 3) return;
        if(node->isEnded) ans.push_back(val);
        for(int i = 0; i < 26; i ++) {
            val.push_back('a' + i);
            dfs(node->children[i], ans, val);
            val.pop_back();
            if(ans.size() == 3) return;
        }
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        sort(products.begin(), products.end());
        for(auto& p : products) trie.put(p);
        vector<vector<string>> ans;
        string cur = "";
        for(char c : searchWord) {
            cur += c;
            ans.push_back(trie.search(cur));
        }
        return ans;
    }
};