// 2949. Count Beautiful Substrings II [H]
// LeetCode count-beautiful-substrings-ii

struct Node {
    int vSum;
    int cSum;
};
class Solution {
public:
    long long calc(int k) {
        long long kPrime = 1;
        int tempK = k;
        for(int i = 2; (long long) i * i <= tempK; i ++) {
            if(tempK % i == 0) {
                int cnt = 0;
                while(tempK % i == 0) {
                    cnt += 1;
                    tempK /= i;
                }
                int powerNeeded = (cnt + 1) / 2;
                for(int j = 0; j < powerNeeded; ++j) {
                    kPrime *= i;
                }
            }
        }
        if(tempK > 1) {
            kPrime *= tempK;
        }
        return kPrime;
    }
    long long beautifulSubstrings(string s, int k) {
        int vSum = 0, cSum = 0;
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o','u' };
        long long ans = 0;
        long long kPrime = calc(k);
        if(kPrime == 0) return 0;
        // cout << kPrime << endl;
        // unordered_map<int, vector<Node>> dict;
        // (diff, (vSum % kPrime, count))
        unordered_map<int, unordered_map<int, int>> dict;
        dict[0][0] += 1;
        for(char c : s) {
            if(vowels.contains(c)) {
                vSum += 1;
            } else {
                cSum += 1;
            }
            int diff = vSum - cSum;
            int curVModKPrime = vSum % kPrime;
            if(dict.contains(diff)) {
                ans += dict[diff][curVModKPrime];
                // for(auto& item : dict[diff]) {
                //     if((item.vSum - vSum) * (item.cSum - cSum) % k == 0) ans += 1;
                // }
            }
            dict[diff][curVModKPrime] += 1;
        }
        return ans;
    }
};