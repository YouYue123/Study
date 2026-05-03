// 2982. Find Longest Special Substring That Occurs Thrice II [M]
// LeetCode find-longest-special-substring-that-occurs-thrice-ii

class Solution {
public:
    bool isValid(int givenLen, string& s) {
        int left = 0, right = 0;
        vector<int> dict(26, 0);
        while(right < s.size()) {
            if(s[right] != s[left]) {
                left = right;
            } else {
                if(right - left + 1 == givenLen) {
                    dict[s[left] - 'a'] += 1;
                    left += 1;
                }
            }
            right += 1;
        }
        for(int i = 0; i < 26; i ++) {
            // cout << dict[i] << " " << endl;
            if(dict[i] >= 3) return true;
        }
        return false;
    }
    int maximumLength(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            // cout << mid << endl;
            if(isValid(mid, s)) {
                // cout << "valid" << endl;
                left = mid + 1;
            } else {
                // cout << "invalid" << endl;
                right = mid;
            }
        }
        return left - 1;
    }
};