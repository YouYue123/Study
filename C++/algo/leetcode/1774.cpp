// 1774. Closest Dessert Cost [M]
// LeetCode closest-dessert-cost

#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <limits>

class Solution {
public:
    int closestCost(std::vector<int>& bases, std::vector<int>& toppings, int target) {
        const int MAX_COST = 200000;
        
        std::set<int> set;
        set.insert(0);

        auto dfs = [&](this auto&& dfs, int i, int prev) {
            if (i == toppings.size()) {
                set.insert(prev);
                return;
            }
            if (prev > MAX_COST) return;
            for (int j = 0; j <= 2; ++j) dfs(i + 1, prev + j * toppings[i]);
        };

        dfs(0, 0);

        int ans = INT_MAX;
        // long long min_diff = std::numeric_limits<long long>::max();

        for (int base : bases) {
            for (int opt : set) {
                int price = base + opt;
                int diff = abs(price - target);
                // cout << opt + base << endl;
                // cout << abs(ans - target) << " " << diff << endl;
                if (diff < abs(ans - target)) {
                    ans = price;
                } else if(diff == abs(ans - target)) {
                    if(price < ans) ans = price;
                }
            }
        }
        
        return ans;
    }
};