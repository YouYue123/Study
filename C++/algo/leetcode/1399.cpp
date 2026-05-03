// 1399. Count Largest Group [E]
// LeetCode count-largest-group

class Solution {
public:
    int getCount(int i) {
        int count = 0;
        while(i > 0) {
            count += i % 10;
            i /= 10;
        }
        return count;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> dict;
        int curMax = 0;
        for(int i = 1; i <= n; i ++) {
            int count = getCount(i);
            dict[count] += 1;
            // cout << count << " " << dict[count] << endl;
            curMax = max(curMax, dict[count]);
        }
        int ans = 0;
        for(auto& p : dict) {
            if(p.second == curMax) ans += 1;
        }
        return ans;
    }
};