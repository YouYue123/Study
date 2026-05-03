// 455. Assign Cookies [E]
// LeetCode assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<>> playerPq;
        priority_queue<int, vector<int>, greater<>> trainerPq;
        for(int p : g) playerPq.push(p);
        for(int t : s) trainerPq.push(t);
        int ans = 0;
        while(!playerPq.empty() && !trainerPq.empty()) {
            if(playerPq.top() <= trainerPq.top()) {
                playerPq.pop();
                trainerPq.pop();
                ans += 1;
            } else {
                trainerPq.pop();
            }
        }
        return ans;
    }
};