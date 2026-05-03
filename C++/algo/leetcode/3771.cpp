#include <bits/stdc++.h>
using namespace std;

// 3771. Total Score of Dungeon Runs [M]
// LeetCode total-score-of-dungeon-runs

struct BIT {
    vector<int> bit;
    int size;
    BIT(int n): size(n), bit(n + 1, 0) {};
    void update(int i, int delta) {
        while(i <= size) {
            bit[i] += delta;
            i += i &(-i);
        }
    }
    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }
};

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long> dmgPreSum(n + 1, 0);
        for(int i = 0; i < n; i ++) {
            dmgPreSum[i + 1] = damage[i] + dmgPreSum[i];
        }
        vector<long long> vals;
        for(long long val : dmgPreSum) vals.push_back(val);
        for(int k = 0; k< n ; k ++) {
            long long ck = dmgPreSum[k + 1] + requirement[k] - hp;
            vals.push_back(ck);
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        auto getRank = [&] (long long val) {
            return distance(vals.begin(), lower_bound(vals.begin(), vals.end(), val)) + 1;
        };
        BIT bit(vals.size());
        long long ans = 0;
        for(int k = 0; k < n; k ++) {
            bit.update(getRank(dmgPreSum[k]), 1);
            long long ck = dmgPreSum[k + 1] + requirement[k] - hp;
            int rankCk = getRank(ck);
            int cntLessThanK = bit.query(rankCk - 1);
            int curP = (k + 1) - cntLessThanK;
            ans += curP;
        }
        // for(int i = 0; i < n; i ++) {
        //     long long left = i, right = n - 1;
        //     long long maxJ = i - 1;
        //     while(left <= right) {
        //         int mid = left + (right - left) / 2;
        //         long long total = ((long long)dmgPreSum[mid + 1] - dmgPreSum[i]) + requirement[mid];
        //         if(hp >= total) {
        //             maxJ = mid;
        //             left = mid + 1;
        //         } else {
        //             right = mid - 1;
        //         }
        //     }
        //     // for(int j = i; j < n; j ++) {
        //     //     // cout << (dmgPreSum[j + 1] - dmgPreSum[i]) + requirement[j] << " ";
        //     //     if(hp >= ((dmgPreSum[j + 1] - dmgPreSum[i]) + requirement[j])) cur += 1;
        //     // }
        //     // cout << endl;
        //     // cout << i << " " << cur << endl;
        //     if(maxJ >= i) ans = ans + (maxJ - i + 1);
        // }
        return ans;
    }
};