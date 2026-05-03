// 3629. Minimum Jumps to Reach End via Prime Teleportation [M]
// LeetCode minimum-jumps-to-reach-end-via-prime-teleportation

long long MAX_N = 1e6 + 1;
vector<vector<int>> primeFactors(MAX_N + 1);
void sieve() {
    for(long long i = 2; i <= MAX_N; i ++) {
        if(primeFactors[i].empty()) {
            // i is prime num
            for(long long j = i; j <= MAX_N; j += i) {
                primeFactors[j].push_back(i);
            }
        }
    }
}
class Solution {
public:
    Solution () {
        if(primeFactors[2].empty()) sieve();
    }
    int minJumps(vector<int>& nums) {
        queue<int> q;
        q.push(0);
        int curStep = 0;
        vector<int> visited(nums.size(), false);
        visited[0] = true;
        unordered_map<int, vector<int>> dict;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] > 1) {
                for(int prime : primeFactors[nums[i]]) {
                    dict[prime].push_back(i);
                }
            }
        }
        while(!q.empty()) {
            int n = q.size();
            while(n --) {
                int curIdx = q.front();
                q.pop();
                // cout << curIdx << endl;
                if(curIdx == nums.size() - 1) return curStep;
                if(curIdx - 1 >= 0 && !visited[curIdx - 1]) {
                    visited[curIdx - 1] = true;
                    q.push(curIdx - 1);
                }
                if(curIdx + 1 < nums.size() && !visited[curIdx + 1]) {
                    visited[curIdx + 1] = true;
                    q.push(curIdx + 1);
                }
                int curNum = nums[curIdx];
                if(dict.contains(curNum)) {
                    for(int nxIdx : dict[curNum]) {
                        q.push(nxIdx);
                    }
                    dict.erase(curNum);
                }
            }
            curStep += 1;
        } 
        return -1;
    }
};