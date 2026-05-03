// 3639. Minimum Time to Activate String [M]
// LeetCode minimum-time-to-activate-string

class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        set<int> stars;
        stars.insert(-1);
        stars.insert(n);
        long long cnt = 0;
        for(int t = 0; t < n; t ++) {
            int pos = order[t];
            auto it = stars.upper_bound(pos);
            int rightStar = *it;
            int leftStar = *prev(it);
            long long leftOptions = pos - leftStar;
            long long rightOptions = rightStar - pos;
            cnt += leftOptions * rightOptions;
            if(cnt >= k) return t;
            stars.insert(pos);
        }
        return -1;
    }
};