// 907. Sum of Subarray Minimums [M]
// LeetCode sum-of-subarray-minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;
        stack<int> mono;
        vector<long long> beforeMin(arr.size(), -1);
        for(int i = arr.size() - 1; i >= 0; i --) {
            while(!mono.empty() && arr[mono.top()] > arr[i]) {
                beforeMin[mono.top()] = i;
                mono.pop();
            }
            mono.push(i);
        }
        long long ans = 0;
        while(!mono.empty()) mono.pop();
        vector<long long> afterMin(arr.size(), arr.size());
        for(int i =0; i < arr.size(); i ++) {
            while(!mono.empty() && arr[mono.top()] >= arr[i]) {
                afterMin[mono.top()] = i;
                mono.pop();
            }
            mono.push(i);
        }
        // cout << "Before min" << endl;
        for(int i = 0; i < arr.size();  i ++) {
            // cout << "arr[i]: " << arr[i] << endl;
            // cout << "Before min: " << beforeMin[i] <<endl;
            // cout << "After min: " << afterMin[i] <<endl;
            long long count = (i - beforeMin[i]) * (afterMin[i] - i);
            // cout << "count: " << count << endl;
            ans = (ans + (count * arr[i])) % MOD;
        }
        return ans;
    }
};