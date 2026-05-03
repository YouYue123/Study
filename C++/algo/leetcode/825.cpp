#include <bits/stdc++.h>
using namespace std;

// 825. Friends Of Appropriate Ages [M]
// LeetCode friends-of-appropriate-ages

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0; // 初始化结果计数器，用于存储可能的加好友请求总数
        sort(ages.begin(), ages.end()); // 对年龄数组进行升序排序
        
        unordered_map<int,int> dict; // 创建哈希表，存储每个年龄首次出现的索引
        for(int i = 0; i < ages.size(); i++) {
            if(!dict.count(ages[i])) dict[ages[i]] = i; // 记录每个年龄的首次出现位置
        }
        
        for(int i = 0; i < ages.size(); i++) {
            // 查找满足加好友条件的最小年龄：2*(ages[i]-7)
            // 根据题目规则，年龄y要满足：y > 0.5*ages[i] + 7
            int x = lower_bound(ages.begin(), ages.end(), 2*(ages[i]-7)) - ages.begin();
            if(x <= i) continue; // 如果找到的位置不大于当前索引，跳过（避免重复计数）
            ans += x - dict[ages[i]] - 1; // 计算可能的加好友请求数
            // x是满足条件的第一个年龄的索引
            // dict[ages[i]]是当前年龄的首次出现索引
            // 两者之差减1表示当前年龄可以发送的请求数
        }
        return ans; // 返回总的加好友请求数
    }
};