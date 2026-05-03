// 3739. Count Subarrays With Majority Element II [H]
// LeetCode count-subarrays-with-majority-element-ii

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using ordered_set = tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int idx = 0;
        int curSum = 0;
        auto st = ordered_set();
        st.insert({ curSum, idx++ });
        long long ans = 0;
        for(int num : nums) {
            curSum += num == target ? 1 : -1;
            ans += st.order_of_key({ curSum, INT_MIN });
            st.insert({ curSum, idx ++ });
        }
        return ans;
    }
};