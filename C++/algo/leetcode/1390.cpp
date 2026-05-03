// 1390. Four Divisors [M]
// LeetCode four-divisors

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            vector<int> divisors;
            for(int i = 1; i * i <= num; i ++) {
                if(num % i == 0) {
                    divisors.push_back(i);
                    if(i * i != num) divisors.push_back(num / i);
                }
                if(divisors.size() > 4) break;
            }
            if(divisors.size() == 4) {
                ans += accumulate(divisors.begin(), divisors.end(), 0);
            }
        }
        return ans;
    }
};