// 1010. Pairs of Songs With Total Durations Divisible by 60 [M]
// LeetCode pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int , int > dict;
        int ans = 0;
        for(int t : time) {
            int comple = (60 - t % 60) % 60;
            ans += dict[comple];
            dict[t % 60] += 1;
        }  
        return ans;
    }
};