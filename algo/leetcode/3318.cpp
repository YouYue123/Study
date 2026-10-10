#include <bits/stdc++.h>
using namespace std;

// 3318. Find X-Sum of All K-Long Subarrays I [E]
// LeetCode find-x-sum-of-all-k-long-subarrays-i

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        // freq, num
        using pii = pair<int, int>;
        // From small to large
        set<pii> validPairs;
        // From large to small
        set<pii, greater<pii>> candidatePairs;
        long long sum = 0;
        unordered_map<int, int> cnt;
        auto add = [&] (int x, int freq) {
            pii p = { freq, x };
            if(p.first == 0) return;
            if(!validPairs.empty() && p >= *validPairs.begin()) {
                sum += (long long)p.first * p.second;
                validPairs.insert(p);
            } else {
                candidatePairs.insert(p);
            }
        };
        auto del = [&] (int x, int freq) {
            pii p = { freq, x };
            if(p.first == 0) return;
            auto it = validPairs.find(p);
            if(it != validPairs.end()) {
                sum -= (long long) p.first * p.second;
                validPairs.erase(it);
            } else {
                candidatePairs.erase(p);
            }
        };
        auto downgrade = [&]() {
            // Choose the smallest valid
            auto p = *validPairs.begin();
            sum -= (long long)p.first * p.second;
            validPairs.erase(p);
            candidatePairs.insert(p);
        };
        auto upgrade = [&] () {
            // Choose the largest candidate
            pii p = *candidatePairs.begin();
            sum += (long long)p.first * p.second;
            validPairs.insert(p);
            candidatePairs.erase(p);
        };
        vector<int> ans(nums.size() - k + 1);
        for(int i = 0; i < nums.size(); i ++) {
            int inNum = nums[i];
            del(inNum, cnt[inNum]);
            cnt[inNum] += 1;
            add(inNum, cnt[inNum]);
            int left = i + 1 - k;
            if (left < 0) continue;
            while(!candidatePairs.empty() && validPairs.size() < x) upgrade();
            while(validPairs.size() > x) downgrade();
            ans[left] = sum;
            int outNum = nums[left];
            del(outNum, cnt[outNum]);
            cnt[outNum] -= 1;
            add(outNum, cnt[outNum]);
        }
        return ans;
    }
};