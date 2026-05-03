// 444. Sequence Reconstruction [M]
// LeetCode sequence-reconstruction

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size(), m = sequences.size();
        unordered_map<int, int> inorder;
        unordered_map<int, vector<int>> g;
        for(auto& s : sequences) {
            for(int i = 0; i < s.size() - 1; i ++) {
                g[s[i]].push_back(s[i + 1]);
                inorder[s[i + 1]] += 1;
            }
        }
        queue<int> q;
        // for(int num = 1; num <= n; num ++) {
        //     if(inorder[num] == 0) q.push(num);
        // }
        if(inorder[nums[0]] != 0) return false;
        q.push(nums[0]);
        vector<int> ans;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int nxt : g[cur]) {
                inorder[nxt] -= 1;
                if(inorder[nxt] == 0) q.push(nxt);
            }
            if(q.size() > 1) return false;
        }
        // for(int num : ans) cout << num << " ";
        // cout << endl;
        return ans == nums;
    }
};