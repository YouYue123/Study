// 208. Implement Trie (Prefix Tree) [M]
// LeetCode implement-trie-prefix-tree

struct TrieNode {
    TrieNode* ch[26];
    bool isEnd;
    TrieNode() {
        for(int i = 0; i < 26; i ++) ch[i] = nullptr;
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(char c : word) {
            int v = c - 'a';
            if(!p->ch[v]) p->ch[v] = new TrieNode();
            p = p->ch[v];
        }
        p->isEnd = true;
    }   
    
    bool search(string word) {
        TrieNode* p = root;
        for(char c : word) {
            int v = c - 'a';
            if(!p->ch[v]) return false;
            p = p->ch[v];
        }
        return p->isEnd;
    } 
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(char c: prefix) {
            int v = c - 'a';
            if(!p->ch[v]) return false;
            p = p->ch[v];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */