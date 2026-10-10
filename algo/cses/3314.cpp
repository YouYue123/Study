#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Treap {
    vector<int> lc;
    vector<int> rc;

    int build(vector<ll>& nums) {
        int n = nums.size();
        lc.assign(n, -1);
        rc.assign(n, -1);
        vector<int> st;
        for(int i = 0; i < n; i ++) {
            int last = -1;
            while(!st.empty() && nums[st.back()] < nums[i]) {
                last = st.back();
                st.pop_back();
            }
            if(last != -1) lc[i] = last;
            if(!st.empty()) rc[st.back()] = i;
            st.push_back(i);
        }
        return st.front();
    }

    int get_left(int x)  { return lc[x]; }
    int get_right(int x) { return rc[x]; } 
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n, 0LL);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto tp = Treap();
    auto root = tp.build(a);
    // cout << root << endl;
    // for(int item : tp.lc) cout << item << " ";
    // cout << endl;
    // for(int item : tp.rc) cout << item << " ";
    // cout << endl;
    vector max_dp(n, 0);
    auto dfs = [&] (auto& dfs, int cur) {
        // cout << cur << endl;
        if(cur == -1) return;
        int left = tp.get_left(cur), right = tp.get_right(cur);
        dfs(dfs, left);
        dfs(dfs, right);
        int ans = 1;
        if(left != -1) {
            ans = max(ans, 1 + max_dp[left]);
        }
        if(right != -1) {
            if(a[right] < a[cur]) {
                ans = max(ans, 1 + max_dp[right]);
            } else {
                int right_left = tp.get_left(right);
                if(right_left != -1) {
                    ans = max(ans, 1 + max_dp[right_left]);
                }
            }
        }

        max_dp[cur] = ans;
        if(left != -1) max_dp[cur] = max(max_dp[cur], max_dp[left]);
        if(right != -1) max_dp[cur] = max(max_dp[cur], max_dp[right]);
    };
    dfs(dfs, root);
    cout << max_dp[root] << endl;
    // cout << 0 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}