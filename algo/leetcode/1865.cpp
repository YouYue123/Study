#include <bits/stdc++.h>
using namespace std;

// 1865. Finding Pairs With a Certain Sum [M]
// LeetCode finding-pairs-with-a-certain-sum

class FindSumPairs {
public:
    unordered_map<long long, int> cnt;
    vector<int> nums1;
    vector<int> nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): nums1(nums1), nums2(nums2) {
        for(int num2 : nums2) cnt[num2] += 1;
    }
    
    void add(int index, int val) {
        cnt[nums2[index]]--;
        nums2[index] += val;
        cnt[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int num : nums1) {
            int res = tot - num;
            if(cnt.contains(res)) ans += cnt[res];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */