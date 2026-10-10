int INF = 0x3f3f3f3f;
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        string cur = "";
        set <string> ans;
        int min_remove = INF;
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(i == n) {
                if(cnt == 0) {
                    int remove = s.size() - cur.size();
                    if(min_remove > remove) {
                        min_remove = remove;
                        ans = {};
                        // cout << "clear " << endl;
                    }
                    if(min_remove == remove) ans.insert(cur);
                }
                return;
            }
            if(s[i] == '(') {
                cur.push_back(s[i]);
                dfs(i + 1, cnt + 1);
                cur.pop_back();
                dfs(i + 1, cnt);
            } else if(s[i] == ')') {
                if(cnt > 0) {
                    cur.push_back(s[i]);
                    dfs(i + 1, cnt - 1);
                    cur.pop_back();
                }
                dfs(i + 1, cnt);
            } else {
                cur.push_back(s[i]);
                dfs(i + 1, cnt);
                cur.pop_back();
            }
            
        };
        dfs(0, 0);
        // cout << min_remove << endl;
        return vector(ans.begin(), ans.end());
    }
};