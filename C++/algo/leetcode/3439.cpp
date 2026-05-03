// 3439. Reschedule Meetings for Maximum Free Time I [M]
// LeetCode reschedule-meetings-for-maximum-free-time-i

struct Gap {
    int start;
    int end;
    int dist;
    Gap(int start, int end): start(start), end(end) {
        dist = end - start;
    }
};
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<Gap> gaps;
        gaps.emplace_back(0, startTime[0]);
        for(int i = 0; i < startTime.size() - 1; i ++) {
            gaps.emplace_back(endTime[i], startTime[i + 1]);
        }
        gaps.emplace_back(endTime.back(), eventTime);
        int left = 0, right = 0, cur = 0;
        int ans = 0;
        while(right < gaps.size()) {
            cur += gaps[right].dist;
            if(right - left + 1 > k + 1) {
                cur -= gaps[left].dist;
                left += 1;
            }
            ans = max(ans, cur);
            right += 1;
        }
        return ans;
    }
};