#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

using pii = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<pii> good_intervals; // 所有"至少选一个"的区间
    vector<ll> bad_diff(n + 1, 0LL); // bad 区间的差分数组
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int k = i + 1;
        // ---- bad 区间：[a*k, (a+1)*k-1]，截到 [0, n-1] 后差分 +1 ----
        ll left = a[i] * k;
        ll right = (a[i] + 1) * k - 1;
        if (left < n) { 
            bad_diff[left]++; 
            right = min(right, (ll)n - 1);
            bad_diff[right + 1]--; 
        }
        // ---- 无解判定 ----
        // 最后一个 good 区间的左端点是 (a-1)*k；若它 >= n，区间里没有可选的数，
        // 该区间永远不能被命中 → 答案为 0。
        // 通过这一步后 a[i] <= n/k + 1，所有 good 区间总数为 O(n log n)。
        if(a[i] > 0 && (a[i] - 1) * k >= n) {
            ok = false;
            break;
        }
        // ---- good 区间：j = 0..a-1，每个 [j*k, (j+1)*k-1] ----
        // 右端点可能 >= n，不用截断：可选的数都 < n，不影响命中判断
        for (int j = 0; j < a[i]; j++)  {
            good_intervals.emplace_back(j * k, (j + 1) * k - 1);
        }
    }
    if(!ok) {
        cout << 0 << endl;
        return;
    }
    // ---- 去掉"包含其他区间"的冗余 good 区间 ----
    // 若 A ⊇ B，命中 B 必命中 A，A 可删。
    // 按右端点升序排（右端点相同，左端点大的在前 = 更短的在前），
    // 只保留左端点严格变大的；被跳过的区间一定包含了某个已保留的区间。
    // 结果：lefts、rights 都严格递增。
    sort(good_intervals.begin(), good_intervals.end(), [](auto& x, auto& y) {
        if (x.second == y.second) return x.first > y.first;
        return x.second < y.second;
    });
    vector<ll> lefts, rights;
    ll mx_left = -1;
    for (auto [left, right] : good_intervals) {
        if (left > mx_left) { 
            lefts.push_back(left);
            rights.push_back(right);
            mx_left = left; 
        }
    }
     // ---- 求可选的数：没有被任何 bad 区间覆盖的 x ----
    vector<int> good_nums;
    for (int x = 0, cur = 0; x < n; x++) {
        cur += bad_diff[x];
        if (cur == 0) good_nums.push_back(x);
    }
    int p = good_nums.size(), q = lefts.size();
    vector<ll> pow_of_2(p + 1, 1);
    for (int i = 1; i <= p; i++) pow_of_2[i] = pow_of_2[i - 1] * 2 % MOD;
     // 没有任何 good 区间：可选的数随便选，答案 2^p
    if(q == 0) {
        cout << pow_of_2[p] << endl;
        return;
    }
    // ---- nxt[i]：第一个 left > good_nums[i] 的区间下标 ----
    // 含义：选了 good_nums[i] 之后，第一个还没被命中的区间。
    // 左端点 <= x 的区间要么已被 x 命中，要么在更早的"跳跃"中已检查过。
    // nxt[i] == q 表示所有区间都已满足。
    vector<int> nxt(p);
    for (int i = 0; i < p; i++) {
        nxt[i] = upper_bound(lefts.begin(), lefts.end(), good_nums[i]) - lefts.begin();
    }
    // get_right(t)：区间 t 的右端点 >= q（没有剩余区间）时为 +∞
    // 选了点 i 后，下一个选中点必须 <= get_right(nxt[i])，否则区间 nxt[i] 被漏掉
    auto get_right = [&] (int t) {
        return t < q ? rights[t] : INF;
    };
    /*
     * dp[i]：点 i 被选中且是"当前最后一个选中点"，
     *        且 good_nums[i] 之前没有漏掉任何区间，的方案数。
     *
     * 一个子集 = 从小到大的一串选中点（没选的点不出现，所以不乘 2）。
     * 转移（枚举链上的前一个点 j）：
     *   dp[i] = [good_nums[i] <= rights[0]]            // i 作为第一个选中点
     *         + Σ dp[j]，j < i 且 get_right(nxt[j]) >= good_nums[i]   // 从 j 跳到 i 不漏区间
     * 答案 = Σ dp[i]，其中 nxt[i] == q（i 作为最后一个点，后面没有区间了）
     *
     * 加速：get_right(nxt[j]) 随 j 单调不降 → 合法的 j 是一段后缀 [left, i-1]；
     *       good_nums[i] 递增 → left 只会右移。
     *       双指针维护 left，前缀和 presum 取区间和，每次转移均摊 O(1)。
     */
    vector dp(p, 0LL);
    vector presum(p + 1, 0LL);
    ll ans = 0;
    for(int i = 0, left = 0;  i < p; i ++) {
        int num = good_nums[i];
        // 踢掉跳不到 num 的前驱：从它们直接跳到 num 会漏掉区间 nxt[left]
        while(left < i && get_right(nxt[left]) < num) left += 1;
        // 所有合法前驱 [left, i-1] 的 dp 之和
        dp[i] = (presum[i] - presum[left] + MOD) % MOD;
        // i 作为第一个选中点：前面不能有被完整漏掉的区间，即 num <= rights[0]
        if(num <= rights[0]) dp[i] = (dp[i] + 1) % MOD;
        presum[i + 1] = (presum[i] + dp[i]) % MOD;
        // i 作为最后一个选中点：之后不能再有区间
        if(nxt[i] == q) ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}