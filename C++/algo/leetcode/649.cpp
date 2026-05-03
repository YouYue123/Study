// 649. Dota2 Senate [M]
// LeetCode dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> dQ, rQ;
        for(int i = 0; i < n; i ++) {
            if(senate[i] == 'D') dQ.push(i);
            else rQ.push(i);
        }
        while(!rQ.empty() && !dQ.empty()) {
            if(rQ.front() < dQ.front()) {
                rQ.push(rQ.front() + n);
            } else {
                dQ.push(dQ.front() + n);
            }
            rQ.pop();
            dQ.pop();
        }
        return rQ.empty() ? "Dire" : "Radiant";
    }
};