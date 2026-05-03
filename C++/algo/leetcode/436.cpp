// 436. Find Right Interval [M]
// LeetCode find-right-interval

struct Item {
    int idx;
    int start;
    int end;
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Item> items;
        for(int i = 0; i < n; i ++) {
            items.emplace_back(
                i,
                intervals[i][0],
                intervals[i][1]
            );
        }
        sort(items.begin(), items.end(), [&] (auto& a, auto& b) {
            return a.start < b.start;
        });
        vector<int> ans;
        auto isValid = [&] (int x, int curEnd) {
            return items[x].start >= curEnd;
        };
        for(auto& interval: intervals) {
            int e = interval[1];
            int left = -1, right = n;
            while(left + 1 < right) {
                int mid = left + (right - left) / 2;
                if(isValid(mid, e)) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            int ansIdx = left + 1;
            if(ansIdx < n) ans.push_back(items[ansIdx].idx);
            else ans.push_back(-1);
        }
        return ans;
    }
};