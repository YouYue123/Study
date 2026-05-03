// 2273. Find Resultant Array After Removing Anagrams [E]
// LeetCode find-resultant-array-after-removing-anagrams

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int left = 0, right = 0;
        while(right < words.size()) {
            string leftCopy = words[left];
            sort(leftCopy.begin(), leftCopy.end());
            string rightCopy = words[right];
            sort(rightCopy.begin(), rightCopy.end());
            if(left == right) ans.push_back(words[left]);
            if(leftCopy == rightCopy) {
                right += 1;
            } else {
                left = right;
            }
        }
        return ans;
    }
};