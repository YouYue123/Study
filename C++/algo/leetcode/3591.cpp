// 3591. Check if Any Element Has Prime Frequency [E]
// LeetCode check-if-any-element-has-prime-frequency

class Solution {
public:
    vector<bool> isPrime;
    void sieve(int maxVal) {
        isPrime.assign(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int p = 2; p * p <= maxVal; p ++) {
            if(isPrime[p]) {
                for(int i = p * p; i <= maxVal; i += p) isPrime[i] = false;
            }
        }
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        sieve(101);
        vector<int> freq(101, 0);
        for(int num : nums) freq[num] += 1;
        for(int i = 0; i < 101; i ++) {
            if(isPrime[freq[i]]) return true;
        }
        return false;
    }
};