// 2975. Maximum Square Area by Removing Fences From a Field [M]
// LeetCode maximum-square-area-by-removing-fences-from-a-field

int MOD = 1e9 + 7;
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(), hFences.end());
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());
        unordered_set<int> set;
        for(int i = 0; i < hFences.size(); i ++) {
            for(int j = i + 1; j < hFences.size(); j ++) {
                set.insert(hFences[j] - hFences[i]);
            }
        }
        int maxLen = 0;
        for(int i = 0; i < vFences.size(); i ++) {
            for(int j = i + 1; j < vFences.size(); j ++) {
                int curDiff = vFences[j] - vFences[i];
                if(set.contains(curDiff)) maxLen = max(maxLen, curDiff);
            }
        }
        return maxLen == 0 ? -1 : (1LL * maxLen * maxLen) % MOD;
    }
};