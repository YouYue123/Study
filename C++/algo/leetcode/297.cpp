// 297. Serialize and Deserialize Binary Tree [H]
// LeetCode serialize-and-deserialize-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return left + "," + right + ","  +to_string(root->val);
    }

    // Decodes your encoded data to tree.
    // "1,2,#,4,#,#,3,#,#,";
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        TreeNode* root;
        list<string> nodes;
        cout << data << endl;
        while(getline(ss, token, ',')) nodes.push_back(token);
        return _deserialize(nodes);
    }

    TreeNode* _deserialize(list<string>& nodes) {
        if(nodes.empty()) return nullptr;
        string cur = nodes.back();
        nodes.pop_back();
        if(cur == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(cur));
        root->right = _deserialize(nodes);
        root->left = _deserialize(nodes);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));