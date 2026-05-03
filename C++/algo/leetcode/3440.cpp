// 3440. Reschedule Meetings for Maximum Free Time II [M]
// LeetCode reschedule-meetings-for-maximum-free-time-ii

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int a = 0, b = -1, c = -1;
        auto get = [&](int i) {
            if(i == 0) return startTime[0];
            if(i == n) return eventTime - endTime.back();
            return startTime[i] - endTime[i - 1];
        };
        for(int i = 1; i <= n; i ++) {
            int cur = get(i);
            if(cur > get(a)) {
                c = b; b = a; a = i;
            } else if(b < 0 || cur > get(b)) {
                c = b; b = i;
            } else if(c < 0 || cur > get(c)) {
                c = i;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            int mSize = endTime[i] - startTime[i];
            bool moveToA = i != a && i + 1 != a && get(a) >= mSize;
            bool moveToB = i != b && i + 1 != b && get(b) >= mSize;
            bool moveToC = i != c && i + 1 != c && get(c) >= mSize;
            if(moveToA || moveToB || moveToC) {
                ans = max(ans, get(i) + mSize + get(i + 1));
            } else {
                ans = max(ans, get(i) + get(i + 1));
            }
        }
        return ans;
    }
};