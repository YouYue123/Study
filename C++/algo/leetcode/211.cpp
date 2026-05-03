// 211. Design Add and Search Words Data Structure [M]
// LeetCode design-add-and-search-words-data-structure

struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
    // ~TrieNode() {
    //     for (int i = 0; i < 26; i++) {
    //         if (children[i]) delete children[i];
    //     }
    // }
};

struct Trie {
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    // ~Trie() {
    //     delete root;
    // }
    void add(string& s) {
        auto* cur = root;
        for(char c : s) {
            if(cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    bool match(string s, TrieNode* cur) {
        int n = s.size();
        // cout << "n: " << n << endl;
        // cout << "s: " << s << endl;
        for(int i = 0; i < n; i ++) {
            // cout << "i: " << i << "n: " << n << endl;
            char c = s[i];
            // cout << "c  " << c << endl;
            if(c == '.') {
                bool hasMatch = false;
                for(int j = 0; j < 26; j ++) {
                    if(cur->children[j] != nullptr) {
                        // cout << "recur" << endl;
                        if(match(s.substr(i + 1), cur->children[j])) {
                            hasMatch = true;
                            break;
                        }
                    }
                }
                return hasMatch;
            } else {
                // cout << "normal match" << endl;
                // cout << (cur->children[c - 'a'] == nullptr ? "Empty" : "HasVal") << endl;
                if(cur->children[c - 'a'] == nullptr) return false;
                cur = cur->children[c - 'a'];
            }
        }
        return cur->isEnd;
    }
};
class WordDictionary {
private:
    Trie trie;
public:
    WordDictionary() {
        trie = Trie();
    }
    
    void addWord(string word) {
        trie.add(word);
    }
    
    bool search(string word) {
        return trie.match(word, trie.root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */