// 2440. Create Components With Same Value [H]
// LeetCode create-components-with-same-value

class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int minEle = *min_element(nums.begin(), nums.end());
        long long sum = 0;
        for(int num : nums) sum += num;
        // cout << sum << endl;
        vector<int> divisors;
        for(int i = 1; i * i <= sum; i ++) {
            if(sum % i == 0) {
                divisors.push_back(i);
                if(i != sum / i) divisors.push_back(sum / i);
            }
        }
        int ans = 0;
        for(int t: divisors) {
            // cout << t << endl;
            int curAns = 0;
            bool valid = false;
            auto dfs = [&](this auto&& dfs, int x, int fa) -> long long {
                long long sum = nums[x];
                for(auto nx : g[x]) {
                    if(nx == fa) continue;
                    sum += dfs(nx, x);
                }
                if(sum == t && fa != -1) {
                    curAns += 1;
                    return 0;
                }
                if(fa == -1) valid = sum == t;
                return sum;
            };
            dfs(0, -1);
            if(valid) ans = max(ans, curAns);
        }
        return ans;
    }
};