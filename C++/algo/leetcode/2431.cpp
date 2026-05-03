// 2431. Maximize Total Tastiness of Purchased Fruits [M]
// LeetCode maximize-total-tastiness-of-purchased-fruits

class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        int n = price.size();
        vector memo(
            n,
            vector(
                maxAmount + 1,
                vector(
                    maxCoupons + 1,
                    -1
                )
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int amt, int cpn) {
            if(amt < 0 || cpn < 0) return INT_MIN / 2;
            if(i == n) return 0;
            if(memo[i][amt][cpn] != -1) return memo[i][amt][cpn];
            return memo[i][amt][cpn] = max({
                dfs(i + 1, amt, cpn),
                dfs(i + 1, amt - price[i], cpn) + tastiness[i],
                dfs(i + 1, amt - price[i] / 2, cpn - 1) + tastiness[i],
            });
        };
        return dfs(0, maxAmount, maxCoupons);
    }
};