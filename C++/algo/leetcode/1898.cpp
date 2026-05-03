// 1898. Maximum Number of Removable Characters [M]
// LeetCode maximum-number-of-removable-characters

class Solution {
public:
    bool isValid(int k, string& s, string& p, vector<int>& removable) {
        vector<bool> removed(s.size(), false);
        for(int i = 0; i < k; i ++) {
            removed[removable[i]] = true;
        }
        int i = 0, j = 0;
        while(i < s.size() && j < p.size()) {
            if(removed[i] == false && s[i] == p[j]) {
                i += 1;
                j += 1;
            } else {
                i += 1;
            }
        }
        return j == p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 1, right = removable.size() + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, s, p, removable)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};