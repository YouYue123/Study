// 2566. Maximum Difference by Remapping a Digit [E]
// LeetCode maximum-difference-by-remapping-a-digit

class Solution {
public:
    int get(int num, char target) {
        string numS = to_string(num);
        bool hasMapped = false;
        unordered_map<char, char> dict;
        for(int i = 0; i <= 9; i ++) dict[i + '0'] = i + '0';
        string ans = "";
        // cout << numS << endl;
        for(int i = 0; i < numS.size(); i ++) {
            if(numS[i] != target && !hasMapped) {
                hasMapped = true;
                dict[numS[i]] = target;
            }
            ans += dict[numS[i]];
        }
        // cout << ans << endl;
        return stoi(ans);
    }
    int minMaxDifference(int num) {
        int minVal = get(num, '0');
        int maxVal = get(num, '9');
        return maxVal - minVal;
    }
};