// 621. Task Scheduler [M]
// LeetCode task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26];
        for(char c : tasks) freq[c - 'A'] += 1;
        priority_queue<int> pq;
        for(int i = 0; i < 26; i ++) {
            if(freq[i] != 0) pq.push(freq[i]);
        }
        int ans = 0;
        while(!pq.empty()) {
            vector<int> wait_list;
            for(int i = 0; i < n + 1; i ++) {
                if(!pq.empty()) {
                    int cur = pq.top();
                    pq.pop();
                    cur -= 1;
                    if(cur > 0) wait_list.push_back(cur);
                }
                ans += 1;
                if(pq.empty() && wait_list.empty()) return ans;
            }
            // cout << wait_list.size() << endl;
            for(int item : wait_list) pq.push(item);
        } 
        return ans;
    }
};