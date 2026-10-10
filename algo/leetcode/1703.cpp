#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<long long> idxes;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)  idxes.push_back(i);
        }
        int m = idxes.size();

        vector<long long> presum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            presum[i + 1] = presum[i] + idxes[i];
        }
        ll ans = -1; 

        for (int i = 0; i <= m - k; i++) {
            int left = i;
            int right = i + k - 1;
            // 找到当前窗口在 idxes 中的中位数下标
            int mid = left + k / 2; 
            // 左半部分(不含 mid)到 mid 的距离和
            // 左边点的个数 * idxes[mid] - (左边所有点的和)
            int left_count = mid - left;
            ll left_dist = left_count * idxes[mid] - (presum[mid] - presum[left]);
            
            // 右半部分(不含 mid)到 mid 的距离和
            // (右边所有点的和) - 右边点的个数 * idxes[mid]
            int right_count = right - mid;
            ll right_dist = (presum[right + 1] - presum[mid + 1]) - right_count * idxes[mid];
            
            ll total_dist = left_dist + right_dist;

            if (ans == -1 || total_dist < ans) {
                ans = total_dist;
            }
        }

        // 4. 减去连续排列所需的固定相对偏移量常数
        // 这个常数只与 k 有关
        ll offset = (ll)(k / 2) * (k - k / 2);
        
        return ans - offset;
    }
};