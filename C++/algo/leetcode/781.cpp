// 781. Rabbits in Forest [M]
// LeetCode rabbits-in-forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for(int a : answers) {
            freq[a] += 1;
        }
        int ans = 0;
        for(auto& p : freq) {
            int a = p.first;
            int cnt = p.second;
            ans += ceil((double)cnt / (a + 1)) * (a + 1);
        }
        return ans;
    }
};