// 1864. Minimum Number of Swaps to Make the Binary String Alternating [M]
// LeetCode minimum-number-of-swaps-to-make-the-binary-string-alternating

class Solution {
public:
    int minSwaps(string s) {
        vector<int> pos1;
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == '1') pos1.push_back(i);
        }
        int oneCount = pos1.size();
        int zeroCount = s.size() - oneCount;
        if(abs(oneCount - zeroCount) > 1) return -1;
        auto calc = [&](int start) -> int {
            if((s.size() - start + 1) / 2 != oneCount) return INT_MAX;
            int ans = 0;
            for(int i = 0; i < pos1.size(); i ++) {
                // cout << pos1[i] << " " << start + i * 2 << endl;
                if(pos1[i] % 2 != start) ans += 1;
                // ans += abs(pos1[i] - (i * 2 + start));
            }
            return ans;
        };
        return min(calc(0), calc(1));
    }
};