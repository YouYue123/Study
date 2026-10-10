#include <bits/stdc++.h>
using namespace std;

// 3551. Minimum Swaps to Sort by Digit Sum [M]
// LeetCode minimum-swaps-to-sort-by-digit-sum

struct Num {
    int num;
    int sumDigit;
    Num(int num): num(num) {
        sumDigit = _sum(num);
    }
    bool operator<(const Num& other) const {
        if(sumDigit == other.sumDigit) {
            return num < other.num;
        } else {
            return sumDigit < other.sumDigit;
        }
    }
    int _sum(int x) {
        int ans = 0;
        while(x != 0) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<Num> sorted;
        for(int num : nums) sorted.emplace_back(num);
        sort(sorted.begin(), sorted.end());
        int swaps = 0;
        int n = nums.size();
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++) {
            if(visited[i] || nums[i] == sorted[i].num) continue;
            int cycle_size = 0;
            int j = i;
            while(!visited[j]) {
                visited[j] = true;
                auto it = lower_bound(sorted.begin(), sorted.end(), nums[j]);
                j = distance(sorted.begin(), it);
                cycle_size++;
            }
            swaps += (cycle_size - 1);
        }
        
        return swaps;
    }
};