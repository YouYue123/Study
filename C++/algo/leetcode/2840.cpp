// 2840. Check if Strings Can be Made Equal With Operations II [M]
// LeetCode check-if-strings-can-be-made-equal-with-operations-ii

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        unordered_map<int, int> odd_freq;
        unordered_map<int, int> even_freq;
        for(int i = 0; i < n; i ++) {
            if(i % 2 == 0) {
                even_freq[s1[i] - 'a'] += 1;
                even_freq[s2[i] - 'a'] -= 1;
            } else {
                odd_freq[s1[i] - 'a'] += 1;
                odd_freq[s2[i] - 'a'] -= 1;
            }
        }
        for(auto& [char_num, freq] : odd_freq) {
            if(freq != 0) return false;
        }
        for(auto& [char_num, freq]: even_freq) {
            if(freq != 0) return false;
        }
        return true;
    }
};