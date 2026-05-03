// 2515. Shortest Distance to Target String in a Circular Array [E]
// LeetCode shortest-distance-to-target-string-in-a-circular-array

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INF;
        for(int i = 0; i < n; i ++) {
            if(words[i] == target) {
                ans = min({
                    ans, 
                    (i - startIndex + n) % n,
                    (startIndex - i + n) % n
                });
            }
        }
        return ans == INF ? -1 : ans;
    }
};