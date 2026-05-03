// 2079. Watering Plants [M]
// LeetCode watering-plants

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cur = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            int p = plants[i];
            if(cur + p > capacity) {
                cur = p;
                ans += i + (i + 1);
                // cout << "refill" << endl;
                // cout << i << endl;
            } else {
                cur += p;
                ans += 1;
            }
            // cout << ans << endl;
        }
        return ans;
    }
};