// 1052. Grumpy Bookstore Owner [M]
// LeetCode grumpy-bookstore-owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        int save = 0, max_save = 0;
        int left = 0, right = 0;
        while(right < n) {
            save += grumpy[right] == 1 ? customers[right] : 0;
            sum += grumpy[right] == 0 ? customers[right] : 0;
            if(right - left + 1 > minutes) {
                save -= grumpy[left] == 1 ? customers[left] : 0;
                left += 1;
            }
            max_save = max(max_save, save);
            right += 1;
        }
        return sum + max_save;
    }
};