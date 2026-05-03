// 3477. Fruits Into Baskets II [E]
// LeetCode fruits-into-baskets-ii

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // unorderd_map<int, int> dict;
        // for(int j = 0; j < baskets.size(); i ++) dict[i] = -1;
        int ans = 0;
        for (int i =0; i < fruits.size(); i ++) {
            bool placed = false;
            for(int j = 0; j < baskets.size(); j ++) {
                // if(dict[j] != -1 && dict[j] != i) {
                //     continue;
                // }
                if(baskets[j] >= fruits[i]) {
                    baskets[j] = 0;
                    placed = true;
                    break;
                }
            }
            if (!placed) ans += 1;
        }
        return ans;
    }
};