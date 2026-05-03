// 1079. Letter Tile Possibilities [M]
// LeetCode letter-tile-possibilities

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        unordered_map<char, int> dict;
        for(char t : tiles) dict[t] += 1;
        int ans = 0;
        auto dfs = [&] (this auto&& dfs) -> void {
            for(int i = 0; i < n; i ++) {
                char c = tiles[i];
                if(i > 0 && tiles[i - 1] == c) continue;
                if(dict[c] == 0) continue;
                dict[c] -= 1;
                ans += 1;
                dfs();
                dict[c] += 1;
            }
        };
        dfs();
        return ans;
    }
};