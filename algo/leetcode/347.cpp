#include <bits/stdc++.h>
using namespace std;

// 347. Top K Frequent Elements [M]
// LeetCode top-k-frequent-elements

struct Item {
    int freq;
    int num;
    // bool operator > (const Item& other) const {
    //     return freq > other.freq;
    // }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority_queue<Item, vector<Item>, greater<>> items;
        unordered_map<int, int> freqs;
        for(int num : nums) {
            freqs[num] += 1;
        }
        vector<Item> items;
        for(auto& [num, freq] : freqs) {
            items.emplace_back(freq, num);
        }
        auto quick_select = [&] (this auto&& dfs, vector<Item>items, int k) -> vector<Item> {
            vector<Item> left, mid, right;
            int pivot = items[rand() % items.size()].freq;
            for(auto& item : items) {
                if(item.freq > pivot) {
                    left.push_back(item);
                } else if(item.freq == pivot) {
                    mid.push_back(item);
                }  else {
                    right.push_back(item);
                }
            }
            if(left.size() >= k) {
                return dfs(left, k);
            } else if(left.size() + mid.size() >= k) {
                vector<Item> ans = std::move(left);
                int needed = k - ans.size();
                ans.insert(ans.end(), mid.begin(), mid.begin() + needed);
                return ans;
            } else {
                vector<Item> ans = std::move(left);
                ans.insert(ans.end(), mid.begin(), mid.end());
                int remaining_k = k - ans.size();
                auto right_top = dfs(right, remaining_k);
                ans.insert(ans.end(), right_top.begin(), right_top.end());
                return ans;
            }
        };
        auto ans = quick_select(items, k);
        vector<int> final_ans;
        for(auto& item : ans) {
            final_ans.push_back(item.num);
        }
        return final_ans;
    }
};