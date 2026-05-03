// 1176. Diet Plan Performance [E]
// LeetCode diet-plan-performance

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int left = 0, right = 0;
        int c = 0;
        int ans = 0;
        while(right < n) {
            c += calories[right];
            if(right - left + 1 > k) {
                c -= calories[left];
                left += 1;
            }
            if(right - left + 1 == k) {
                if(c > upper) ans += 1;
                if(c < lower) ans -= 1;
            }
            right += 1;
        }
        return ans;
    }
};