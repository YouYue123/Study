#include <bits/stdc++.h>
using namespace std;

// 3321. Find X-Sum of All K-Long Subarrays II [H]
// LeetCode find-x-sum-of-all-k-long-subarrays-ii

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using pii = pair<long long, long long>;
        set<pii> valid;
        set<pii, greater<pii>> candidate;
        vector<long long> ans;
        unordered_map<int, int> cnt;
        long long curSum = 0;
        auto add = [&] (int x, int freq) {
            if(freq == 0) return;
            auto item = pii(freq, x);
            if(!valid.empty() && item >= (*valid.begin())) {
                valid.insert(item);
                curSum += item.first * item.second;
            }
            else {
                candidate.insert(item);
            }
        };
        auto del = [&](int x, int freq) {
            if(freq == 0) return;
            auto item = pii(freq, x);
            auto it = valid.find(item);
            if(it != valid.end()) {
                curSum -= it->first * item.second;
                valid.erase(it);
            } else {
                candidate.erase(item);
            }
        };
        auto upgrade = [&]() {
            auto it = *candidate.begin();
            valid.insert(it);
            curSum += it.first * it.second;
            candidate.erase(it);
        };
        auto downgrade = [&]() {
            auto it = *valid.begin();
            curSum -= it.first * it.second;
            candidate.insert(it);
            valid.erase(it);
        };
        int left = 0;
        for(int right = 0; right < nums.size(); right ++) {
            int rNum = nums[right];
            del(rNum, cnt[rNum]);
            cnt[rNum] += 1;
            add(rNum, cnt[rNum]);
            while(valid.size() > x) downgrade();
            while(!candidate.empty() && valid.size() < x) upgrade();
            if(right - left + 1 < k) continue;
            ans.push_back(curSum);
            int lNum = nums[left];
            del(lNum, cnt[lNum]);
            cnt[lNum] -= 1;
            add(lNum, cnt[lNum]);
            left += 1;
        }
        return ans;
    }
};