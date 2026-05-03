// 2410. Maximum Matching of Players With Trainers [M]
// LeetCode maximum-matching-of-players-with-trainers

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int, vector<int>, greater<>> playerPq;
        priority_queue<int, vector<int>, greater<>> trainerPq;
        for(int p : players) playerPq.push(p);
        for(int t : trainers) trainerPq.push(t);
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