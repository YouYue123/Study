// 2861. Maximum Number of Alloys [M]
// LeetCode maximum-number-of-alloys

class Solution {
public:
    int isValid(int x, int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        bool canProduce = false;
        for(int i = 0; i < k; i ++) {
            auto& machine = composition[i];
            long long curCost = 0;
            for(int j = 0; j < n; j ++) {
                long long comp = machine[j];
                long long s = stock[j];
                long long c = cost[j];
                curCost += max(comp * x - s, 0LL) * c;
                if(curCost > budget) break;
            }
            if(curCost <= budget) {
                canProduce = true;
                break;
            }
        }
        // cout << x << " " << canProduce << endl;
        return canProduce;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int left = 1, right = 1e9;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, n, k, budget, composition, stock, cost)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};