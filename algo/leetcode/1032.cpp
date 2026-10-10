#include <bits/stdc++.h>
using namespace std;

// 1032. Stream of Characters [H]
// LeetCode stream-of-characters

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for(int i = 0; i < 26; i ++)  children[i] = nullptr;
        isEnd = false;
    }
    TrieNode* get(int c) {
        return children[c - 'a'];
    }
    void put(int c) {
        children[c - 'a'] = new TrieNode();
    }
    bool getIsEnd() {
        return this->isEnd;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void add(string w) {
        TrieNode* node = root;
        for(char c: w) {
            if(!node->get(c)) node->put(c);
            node = node->get(c);
        }
        node->isEnd = true;
    }
    
    bool isSuffixOf(string& w) {
        TrieNode* node = root;
        for(int i = w.size() - 1; i >=0 ; i --) {
            char c = w[i];
            if(!node->get(c)) return false;
            node = node->get(c);
            if(node->isEnd) return true;
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie* trie;
    string cur;   
    StreamChecker(vector<string>& words) {
        trie = new Trie();
        cur = "";
        for(string& w : words) {
            reverse(w.begin(), w.end());
            trie->add(w);
        }
    }
    
    bool query(char letter) {
        cur += letter;
        return trie->isSuffixOf(cur);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */