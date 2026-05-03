// 2960. Count Tested Devices After Test Operations [E]
// LeetCode count-tested-devices-after-test-operations

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        vector<int> diff(n + 1, 0);
        diff[0] = batteryPercentages[0];
        for(int i = 1; i < n; i ++) {
            diff[i] = batteryPercentages[i] - batteryPercentages[i - 1];
        }
        int ans = 0;
        int cur = 0;
        for(int i = 0; i < n; i ++) {
            cur += diff[i];
            if(cur > 0) {
                ans += 1;
                diff[i + 1] -= 1;
                // diff[n] += 1;
            }
        }
        return ans;
    }
};