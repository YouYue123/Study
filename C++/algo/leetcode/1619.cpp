// 1619. Mean of Array After Removing Some Elements [E]
// LeetCode mean-of-array-after-removing-some-elements

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int count = int(arr.size() * 0.05);
        // cout << count << endl;
        double sum = 0.0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i< arr.size(); i ++) {
            if(i < count || i > arr.size() - count - 1) continue;
            sum += arr[i];
        }
        return sum / (arr.size() - 2 * count);
    }
};