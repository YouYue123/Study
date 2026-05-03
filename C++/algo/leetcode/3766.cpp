// 3766. Minimum Operations to Make Binary Palindrome [M]
// LeetCode minimum-operations-to-make-binary-palindrome

class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> palinds;
        auto gen = [&](int len) {
            int halfLen = (len + 1) / 2;
            int start = 1 << (halfLen - 1);
            int end = 1 << halfLen;
            for(int i = start; i < end; i ++) {
                int palin = i;
                int mirror = i;
                if(len % 2 != 0) mirror >>= 1;
                for(int i = 0; i < len / 2; i ++) {
                    palin = (palin << 1) | (mirror & 1);
                    mirror >>= 1;
                }
                if(palin <= 8192) palinds.push_back(palin);
            }
        };
        palinds.push_back(1);
        for(int len = 2; len <= 14; len ++)  gen(len);
        sort(palinds.begin(), palinds.end());
        palinds.erase(unique(palinds.begin(), palinds.end()), palinds.end());
        vector<int> ans;
        for(int num : nums) {
            auto it = lower_bound(palinds.begin(), palinds.end(), num);
            int minOps = INT_MAX;
            if(it != palinds.end()) {
                minOps = min(minOps, abs(*it - num));
            }
            if(it != palinds.begin()) {
                minOps = min(minOps, abs(*prev(it) - num));
            }
            ans.push_back(minOps);
        }
        return ans;
    }
};