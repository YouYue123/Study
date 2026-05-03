// 3479. Fruits Into Baskets III [M]
// LeetCode fruits-into-baskets-iii

class SegmentTree {
private:
    vector<int> tree;
    int n;

    // Build the segment tree from the baskets array
    void build(int node, int start, int end, const std::vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            tree[node] = std::max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // Query the leftmost index where value >= x
    int query(int node, int start, int end, int x) {
        if (start == end) return (tree[node] >= x) ? start : -1;
        int mid = (start + end) / 2;
        if (tree[2 * node] >= x) return query(2 * node, start, mid, x);
        else if (tree[2 * node + 1] >= x) return query(2 * node + 1, mid + 1, end, x);
        return -1; // No suitable basket found
    }

    // Update a basket's capacity (set to -1 when assigned)
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = std::max(tree[2 * node], tree[2 * node + 1]);
        }
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); // Allocate enough space (4n is sufficient for a segment tree)
        build(1, 0, n - 1, arr);
    }

    int findLeftmost(int x) {
        return query(1, 0, n - 1, x);
    }

    void setAssigned(int idx) {
        update(1, 0, n - 1, idx, -1);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree st(baskets);
        int unplaced = 0;
        for (int i = 0; i < n; i++) {
            int j = st.findLeftmost(fruits[i]);
            if (j != -1) st.setAssigned(j);
            else unplaced++;
        }
        return unplaced;
    }
};