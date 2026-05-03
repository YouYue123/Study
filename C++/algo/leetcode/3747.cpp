// 3747. Count Distinct Integers After Removing Zeros [M]
// LeetCode count-distinct-integers-after-removing-zeros

class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int L = s.size();
        long long ans = 0;
        vector<long long> pow9(L + 1);
        pow9[0] = 1;
        for(int i = 1; i <= L; i ++) {
            if(pow9[i - 1] > LLONG_MAX / 9) {
                pow9[i] = LLONG_MAX;
            } else {
                pow9[i] = pow9[i - 1] * 9;
            }
        }
        for(int len = 1; len < L; len ++) ans += pow9[len];
        for(int i = 0; i < L; i ++) {
            int d = s[i] - '0';
            for(int c = 1; c < d; c++) ans += pow9[L- 1 - i];
            if(d == 0) break;
            if(i == L - 1) ans += 1;
        }
        return ans;
    }
};