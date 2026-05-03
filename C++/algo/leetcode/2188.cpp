// 2188. Minimum Time to Finish the Race [H]
// LeetCode minimum-time-to-finish-the-race

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<long long> dict(18, INF);
        dict[0] = 0;
        for(auto& t : tires) {
            int f = t[0], r = t[1];
            long long sum = 0;
            int lap = 1;
            for(long long time = f; time < changeTime + f; time *= r, lap += 1) {
                sum += time;
                dict[lap] = min(dict[lap], sum);
            }
        }
        // for(int item: dict) cout << item << " ";
        // cout << endl;
        vector memo(numLaps + 1, -1);
        auto dfs = [&] (this auto&& dfs, int lap) -> long long {
            if(lap == 0) return 0;
            if(memo[lap] != -1) return memo[lap];
            long long ans = INF;
            for(int i = 1; i <= min(lap, 17); i ++) {
                if(dict[i] == INF) continue;
                // int restLap = lap - nxtLap;
                // cout << i << " " << lap - i << endl;
                ans = min(
                    ans,
                    dict[i] + changeTime + dfs(lap - i)
                );
            }
            return memo[lap] = ans;
        };

        return dfs(numLaps) - changeTime;
    }
};