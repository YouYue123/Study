// 1427. Perform String Shifts [E]
// LeetCode perform-string-shifts

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        vector<int> overShifts(2, 0);
        for (vector<int>& move: shift) {
            overShifts[move[0]] += move[1];
        }
        int leftShifts = overShifts[0];
        int rightShifts = overShifts[1];
        int n = s.length();
        string ans = s;
        if(leftShifts > rightShifts) {
            leftShifts = (leftShifts - rightShifts) % n;
            ans = s.substr(leftShifts) + s.substr(0, leftShifts);
        } else if (rightShifts > leftShifts) {
            rightShifts = (rightShifts - leftShifts) % n;
            ans = s.substr(n - rightShifts) + s.substr(0, n-rightShifts);
        }
        return ans;
    }
};