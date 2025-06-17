#include <string>
using namespace std;
struct TrieNode {
    TrieNode* ch[26];
    bool is_end;
    TrieNode() {
       for(int i = 0; i < 26; i ++) {
        ch[i] = nullptr;
       }
       is_end = false;
    }
};
struct Trie {
    TrieNode* root; // root is a dummy node
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& s) {
        TrieNode* p = root;
        for(auto c : s) {
            int v = c - 'a';
            if(!p->ch[v]) p->ch[v] = new TrieNode();
            p = p->ch[v];
        }
        p->is_end = true;
    } 
    bool query(const string& s) {
        TrieNode* p = root;
        for(auto c : s) {
            int v = c - 'a';
            if(!p->ch[v]) return false;
            p = p->ch[v];
        }
        return p->is_end;
    }
    bool query_prefix(const string& s) {
        TrieNode* p = root;
        for(auto c : s) {
            int v = c - 'a';
            if(!p->ch[v]) return false;
            p = p->ch[v];
        }
        return true;
    }
};