#include <bits/stdc++.h>
using namespace std;

// 632. Smallest Range Covering Elements from K Lists [H]
// LeetCode smallest-range-covering-elements-from-k-lists

struct Node {
    int val;
    int listIndex;
    int itemIndex;
    Node(int val, int listIndex, int itemIndex): val(val), listIndex(listIndex), itemIndex(itemIndex) {}
    bool operator < (const Node& other) const {
        return val < other.val;
    }
    bool operator >(const Node& other) const {
        return val > other.val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // 使用最小堆，堆顶始终是当前所有列表中最小的元素
        priority_queue<Node, vector<Node>, greater<>> pq;
        
        int maxVal = INT_MIN;  // 记录当前堆中所有元素的最大值
        int start = 0, end = INT_MAX;  // 初始化结果范围为最大可能范围
        
        // 初始化：将每个列表的第一个元素加入堆
        for(int i = 0; i < nums.size(); i++) {
            pq.emplace(nums[i][0], i, 0);  // 创建节点并加入堆
            maxVal = max(maxVal, nums[i][0]);  // 更新当前最大值
        }
        
        // 只要堆中包含所有列表的元素（即每个列表至少有一个元素在堆中）
        while(pq.size() == nums.size()) {
            auto cur = pq.top();  // 获取当前最小值
            pq.pop();  // 移除最小值
            
            // 如果当前范围比之前找到的更小，更新结果
            if(maxVal - cur.val < end - start) {
                end = maxVal;
                start = cur.val;
            }
            
            // 如果当前元素所在列表还有下一个元素
            if(cur.itemIndex < nums[cur.listIndex].size() - 1) {
                int nextNum = nums[cur.listIndex][cur.itemIndex + 1];  // 获取下一个元素
                maxVal = max(maxVal, nextNum);  // 更新最大值
                // 将下一个元素加入堆
                pq.emplace(nextNum, cur.listIndex, cur.itemIndex + 1);
            }
        }
        
        return {start, end};  // 返回找到的最小范围
    }
};