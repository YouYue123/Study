// 212. Word Search II [H]
// LeetCode word-search-ii

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
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
    void add(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->get(c)) node->put(c);
            node = node->get(c);
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string& word : words) {
            trie.add(word);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, trie.root, "", result);
            }
        }

        // Remove duplicates by using a set
        unordered_set<string> uniqueResult(result.begin(), result.end());
        return vector<string>(uniqueResult.begin(), uniqueResult.end());
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, string currentStr, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') {
            return;
        }

        char originalChar = board[i][j];
        TrieNode* nextNode = node->get(originalChar);
        if (!nextNode) return;

        currentStr += originalChar;

        if (nextNode->isEnd) {
            result.push_back(currentStr);
            nextNode->isEnd = false; // Prevent adding the same word again
        }

        board[i][j] = '#'; // Mark as visited

        // Explore all four directions
        dfs(board, i + 1, j, nextNode, currentStr, result);
        dfs(board, i - 1, j, nextNode, currentStr, result);
        dfs(board, i, j + 1, nextNode, currentStr, result);
        dfs(board, i, j - 1, nextNode, currentStr, result);

        board[i][j] = originalChar; // Backtrack
    }
};