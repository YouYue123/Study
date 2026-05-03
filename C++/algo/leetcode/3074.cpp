// 3074. Apple Redistribution into Boxes [E]
// LeetCode apple-redistribution-into-boxes

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size();
        sort(capacity.begin(), capacity.end());
        int sum = 0;
        int total = 0;
        for(int i = 0; i < n; i ++) total += apple[i];
        for(int i = m - 1; i >= 0; i --) {
            sum += capacity[i];
            if(sum >= total) return m - i;
        }
        return -1;
    }
};