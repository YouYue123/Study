// 1522. Diameter of N-Ary Tree [M]
// LeetCode diameter-of-n-ary-tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans = 0;
    int dfs(Node* root, int depth) {
        if (!root) return depth;
        int maxDepth1 = depth, maxDepth2 = 0;
        for(auto child : root->children) {
            int curDepth = dfs(child, depth + 1);
            if(curDepth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = curDepth;
            } else if(curDepth > maxDepth2) {
                maxDepth2 = curDepth;
            }
            // cout << curDepth << endl;
            int dist = maxDepth1 + maxDepth2 - 2 * depth;
            ans = max(ans, dist);
        }
        return maxDepth1;
    }
    int diameter(Node* root) {
        dfs(root, 0);
        return ans;
    }
};