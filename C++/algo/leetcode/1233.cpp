// 1233. Remove Sub-Folders from the Filesystem [M]
// LeetCode remove-sub-folders-from-the-filesystem

struct TrieNode {
    string val;
    unordered_map<string, TrieNode*> children;
    bool isEnd;
};
struct Trie {
    TrieNode* root;
    Trie () {
        root = new TrieNode();
    }
    bool insert(string s) {
            int i = 1;
            TrieNode* cur = root;
            // cout << "s: " << s << endl;
            while(i < s.size()) {
                string curS = "";
                while(i < s.size() && s[i] != '/') {
                    curS += s[i];
                    i += 1;
                }
                // cout << curS << endl;
                if(!cur->children.contains(curS)) {
                    // cout << "new children" << endl;
                    cur->children[curS] = new TrieNode();
                }
                cur = cur->children[curS];
                if(cur->isEnd) return false;
                i += 1;
            }
            cur->isEnd = true;
            return true;
    }
};
class Solution {
public:
    void dfs(TrieNode* root, vector<string>& ans, string curS) {
        curS += "/" + root->val;

    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        Trie* trie = new Trie();
        for(string& f : folder) {
            if(trie->insert(f)) {
                ans.push_back(f);
            }
        }
        return ans;
    }
};