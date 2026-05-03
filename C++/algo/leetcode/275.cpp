// 275. H-Index II [M]
// LeetCode h-index-ii

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 1;
        int right = citations.size() + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(citations[n - mid] >= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1; 
    }
};