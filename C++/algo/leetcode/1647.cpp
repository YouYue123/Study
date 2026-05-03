// 1647. Minimum Deletions to Make Character Frequencies Unique [M]
// LeetCode minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:
    int minDeletions(string s) {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s) {
            frequency[c - 'a']++;
        }
        
        sort(frequency.begin(), frequency.end(), greater<int>());
        
        int deleteCount = 0;
        // Maximum frequency the current character can have
        int maxFreqAllowed = s.size();
        for(auto a : frequency) {
            cout << a << endl;
            
        }
        // Iterate over the frequencies in descending order
        for (int i = 0; i < 26 && frequency[i] > 0; i++) {
            // Delete characters to make the frequency equal the maximum frequency allowed
            if (frequency[i] > maxFreqAllowed) {
                deleteCount += frequency[i] - maxFreqAllowed;
                frequency[i] = maxFreqAllowed;
            }
            // Update the maximum allowed frequency
            maxFreqAllowed = max(0, frequency[i] - 1);
        }
        
        return deleteCount;
    }
};