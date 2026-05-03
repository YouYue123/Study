// 2551. Put Marbles in Bags [H]
// LeetCode put-marbles-in-bags

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairWeights;
        for(int i = 0; i < n - 1; i ++) {
            pairWeights.push_back(
                weights[i] + weights[i + 1]
            );
        }

        sort(pairWeights.begin(), pairWeights.end());
        long long ans = 0;
        for(int weight: pairWeights) cout << weight << " ";
        cout << endl;
        for(int i = 0; i < k - 1; i ++) {
            ans += pairWeights[n - i - 2] - pairWeights[i];
        }
        return ans;
    }
};