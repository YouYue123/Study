#include <bits/stdc++.h>
using namespace std;

// 720. Longest Word in Dictionary [M]
// LeetCode longest-word-in-dictionary

struct Node {
    bool is_end;
    Node* children[26];
    Node(bool is_end): is_end(is_end) {
        for(int i = 0 ; i< 26; i ++) children[i] = nullptr;
    };
};
struct Trie {
    Node* root;
    Trie () {
        root = new Node(false);
    }
    bool add(const string& word) {
        int n = word.size();
        Node* cur = root;
        bool has_all_precedent = true;
        for(int i = 0; i < n; i ++) {
            char c = word[i];
            if(cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new Node(false);
            }
            cur = cur->children[c - 'a'];
            if(i != n - 1 && cur->is_end == false) {
                has_all_precedent = false;
            }
        }
        cur->is_end = true;
        return has_all_precedent;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string ans = "";
        Trie trie;
        for(auto& w : words) {
            if(trie.add(w)) {
                if(ans.size() < w.size()) {
                    ans = w;
                } else {
                    if(ans > w) {
                        ans = w;
                    }
                }
            }
        }
        return ans;
    }
};