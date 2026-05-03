// 1244. Design A Leaderboard [M]
// LeetCode design-a-leaderboard

class Leaderboard {
private:
    unordered_map<int, int> player2Score;
    map<int, int, greater<>> scoreToPlayerCnt;
    void _deductCnt(int score) {
        if(scoreToPlayerCnt[score] == 1) scoreToPlayerCnt.erase(score);
        else scoreToPlayerCnt[score] -= 1;
    }
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        int oldScore = 0;
        if(player2Score.contains(playerId)) {
            oldScore = player2Score[playerId];
            _deductCnt(oldScore);
        }
        int newScore = oldScore + score;
        player2Score[playerId] = newScore;
        scoreToPlayerCnt[newScore] += 1;
    }
    
    int top(int K) {
        int cnt = 0, ans = 0;
        for(auto& [score, playerCnt] : scoreToPlayerCnt) {
            if(cnt + playerCnt <= K) {
                ans += score * playerCnt;
                cnt += playerCnt;
            } else {
                for(int i = 0; i < playerCnt; i ++) {
                    ans += score;
                    cnt += 1;
                    if(cnt == K) break;
                }
            }
            if(cnt == K) break;
        }
        return ans;
    }
    
    void reset(int playerId) {
        int oldScore = player2Score[playerId];
        _deductCnt(oldScore);
        player2Score.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */