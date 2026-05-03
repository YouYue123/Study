// 2843.   Count Symmetric Integers [E]
// LeetCode count-symmetric-integers

class Solution {
public:
    bool isValid(int num) {
        string is = to_string(num);
        if(is.size() % 2 == 1) return false;
        int i = 0, j = is.size() - 1;
        long long preSum = 0, postSum = 0;
        while(i < j) {
            preSum += is[i] - '0';
            postSum += is[j] - '0';
            i += 1;
            j -= 1;
        }
        return preSum == postSum;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i ++) {
            if(isValid(i)) {
                ans += 1;
                // cout << "isValid: " << i << endl;
            }
        }
        return ans;
    }
};