// 1361. Validate Binary Tree Nodes [M]
// LeetCode validate-binary-tree-nodes

class UF {
public:
int count;
vector<int> parent;
UF (int n) {
    count = n;
    parent.resize(n);
    for(int i = 0; i < n; i ++) parent[i] = i;
}
void union_(int p, int q) {
    int rootP = findRoot(p);
    int rootQ = findRoot(q);
    if(rootP == rootQ) return;
    parent[rootP] = rootQ;
    count -= 1;
}
int findRoot(int x) {
    if(parent[x] == x) return x;
    int root = findRoot(parent[x]);
    parent[x] = x;
    return root;
}
bool connected(int p, int q) {
    return findRoot(p) == findRoot(q);
}
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n);
        for(int i = 0; i < n; i ++) {
            if(leftChild[i] != -1) indegree[leftChild[i]] += 1;
            if(rightChild[i] != -1) indegree[rightChild[i]] += 1;
        }
        int root = -1;
        for(int i = 0; i < n; i ++) {
            if(indegree[i] == 0) {
                if(root != -1) return false;
                root = i;
            } else {
                if(indegree[i] != 1) return false;
            }
        }
        // cout << "before uf" << endl;
        UF uf = UF(n);
        for(int i = 0; i < n; i ++) {
            int left = leftChild[i];
            int right = rightChild[i];
            if(left != -1) {
                if(uf.connected(i, left)) return false;
                uf.union_(i, left);
            }
            if(right != -1) {
                if(uf.connected(i, right)) return false;
                uf.union_(i, right);
            }
            // cout << "uf" << endl;
        }
        return uf.count == 1;
    }
};