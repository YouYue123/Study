// 2999. Count the Number of Powerful Integers [H]
// LeetCode count-the-number-of-powerful-integers

class Solution {
public:
    string low;
    string high;
    int preLen;
    int limit;
    string s;
    unordered_map<int, long long> memo;
    long long dfs(int i, bool limitLow, bool limitHigh) {
        if(i == low.size()) return 1;
        if(!limitLow && !limitHigh && memo.contains(i)) return memo[i];
        int lo = limitLow ? low[i] - '0' : 0;
        int hi = limitHigh ? high[i] - '0': 9;
        long long ans = 0;
        if(i < preLen) {
            for(int digit = lo; digit <= min(hi, limit); digit ++) {
                ans += dfs(i+1, limitLow && digit == lo, limitHigh && digit == hi);
            }
        } else {
            int x = s[i - preLen] - '0';
            if(lo <= x && x <= min(hi, limit)) {
                ans = dfs(i + 1, limitLow && x == lo, limitHigh && x == hi);
            }

        }
        if(!limitLow && !limitHigh) {
            return memo[i] = ans;
        }
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        this->low = to_string(start);
        this->high = to_string(finish);
        this->limit = limit;
        this->s = s;
        this->low = string(high.size() - low.size(), '0') + low;
        this->preLen = high.size() - s.size();
        return dfs(0, true, true);
    }
};