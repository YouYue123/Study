// 378. Kth Smallest Element in a Sorted Matrix [M]
// LeetCode kth-smallest-element-in-a-sorted-matrix

typedef vector<int> Tuple3;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Tuple3, vector<Tuple3>, greater<>> pq;
        for(int i = 0; i < matrix.size(); i ++) {
            pq.push({matrix[i][0], i, 0 });
        }
        int ans = 0;
        while(!pq.empty() && k > 0) {
            Tuple3 cur = pq.top();
            pq.pop();
            ans = cur[0];
            k -= 1;
            int i = cur[1], j = cur[2];
            if(j + 1 < matrix[i].size()) {
                // cout << "push in : " <<  matrix[i][j + 1]  << endl;
                pq.push({ 
                    matrix[i][j + 1] ,
                    i,
                    j + 1,
                });
            }
        }
        return ans;
    }
};