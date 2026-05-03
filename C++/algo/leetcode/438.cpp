// 438. Find All Anagrams in a String [M]
// LeetCode find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pDict;
        for(char c : p) {
            pDict[c] += 1;
        }
        int count = 0;
        unordered_map<char, int> dict;
        int left =0, right = 0;
        vector<int> ans;
        while(right < s.size()) {
            dict[s[right]] += 1;
            if(pDict.contains(s[right]) && dict[s[right]] == pDict[s[right]]) count += 1;
            if(right - left + 1 > p.size()) {
                if(pDict.contains(s[left]) && dict[s[left]] == pDict[s[left]]) count -= 1;
                dict[s[left]] -= 1;
                left += 1;
            }
            // cout << left << " " << right << endl;
            // cout << "count: " << count << " " << pDict.size() <<endl;
            if(count == pDict.size()) ans.push_back(left);
            right += 1;
        }
        return ans;
    }
};