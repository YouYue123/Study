// 2416. Sum of Prefix Scores of Strings [H]
// LeetCode sum-of-prefix-scores-of-strings

class TrieNode {
public:
bool isEnd;
TrieNode* children[26];
int count;
    TrieNode() {
        isEnd = false;
        count = 0;
        for(int i = 0; i < 26; i ++) children[i] = nullptr;
    }

    TrieNode* get(char c) {
        return children[c - 'a'];
    }

    void put(char c) {
        children[c - 'a'] = new TrieNode();
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->get(c)) node->put(c);
            node = node->get(c);
            node->count += 1;
        }
        node->isEnd = true;
    }

    bool isPrefix(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            if(!node->get(c)) return false;
            node = node->get(c);
        }
        return true;
    }
};
class Solution {
public:
    // Calculate the prefix count using this function.
    int count(string s, TrieNode* root) {
        int ans = 0;
        // The ans would store the total sum of counts.
        for (char c : s) {
            ans += root->children[c - 'a']->count;
            root = root->children[c - 'a'];
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> memo;
        Trie* trie = new Trie();
        for(string& word: words) {
            if(trie->isPrefix(word)) {
                cout << word << " has prefix in the trie" << endl;
            }
            trie->insert(word);
        }
        for(string& word: words) ans.push_back(count(word, trie->root));
        return ans;
    }
};