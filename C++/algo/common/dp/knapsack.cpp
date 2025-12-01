
#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/dp/knapsack/
constexpr int MAXN = 1e4 + 5;
constexpr int MAXW = 1e7 + 5;
int n, W, w[MAXN], v[MAXN];
long long f[MAXW];

// https://oi-wiki.org/dp/knapsack/#0-1-%E8%83%8C%E5%8C%85
// 0-1 背包
int main()
{
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i]; // 读入数据
    for (int i = 1; i <= n; i++)
        for (int l = W; l >= w[i]; l--)
            if (f[l - w[i]] + v[i] > f[l])
                f[l] = f[l - w[i]] + v[i]; // 状态方程
    cout << f[W];
    return 0;
}

// https://oi-wiki.org/dp/knapsack/#%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85
// 完全背包
int main()
{
    cin >> W >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++)
        for (int l = w[i]; l <= W; l++)
            if (f[l - w[i]] + v[i] > f[l])
                f[l] = f[l - w[i]] + v[i]; // 核心状态方程
    cout << f[W];
    return 0;
}

// https://oi-wiki.org/dp/knapsack/#%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85
// 多重背包
for (int i = 1; i <= n; i++) {
    for (int weight = W; weight >= w[i]; weight--) {
      // 多遍历一层物品数量
      for (int k = 1; k * w[i] <= weight && k <= cnt[i]; k++) {
        dp[weight] = max(dp[weight], dp[weight - k * w[i]] + k * v[i]);
      }
    }
  }

// https://oi-wiki.org/dp/knapsack/#%E6%B7%B7%E5%90%88%E8%83%8C%E5%8C%85
// 混合背包
for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {  // 如果数量没有限制使用完全背包的核心代码
      for (int weight = w[i]; weight <= W; weight++) {
        dp[weight] = max(dp[weight], dp[weight - w[i]] + v[i]);
      }
    } else {  // 物品有限使用多重背包的核心代码，它也可以处理0-1背包问题
      for (int weight = W; weight >= w[i]; weight--) {
        for (int k = 1; k * w[i] <= weight && k <= cnt[i]; k++) {
          dp[weight] = max(dp[weight], dp[weight - k * w[i]] + k * v[i]);
        }
      }
    }
  }

// https://oi-wiki.org/dp/knapsack/#%E4%BA%8C%E7%BB%B4%E8%B4%B9%E7%94%A8%E8%83%8C%E5%8C%85
// 二维背包
for (int k = 1; k <= n; k++)
  for (int i = m; i >= mi; i--)    // 对经费进行一层枚举
    for (int j = t; j >= ti; j--)  // 对时间进行一层枚举
      dp[i][j] = max(dp[i][j], dp[i - mi][j - ti] + 1);

// https://oi-wiki.org/dp/knapsack/#%E5%88%86%E7%BB%84%E8%83%8C%E5%8C%85
// 分组背包
for (int k = 1; k <= ts; k++)          // 循环每一组
  for (int i = m; i >= 0; i--)         // 循环背包容量
    for (int j = 1; j <= cnt[k]; j++)  // 循环该组的每一个物品
      if (i >= w[t[k][j]])             // 背包容量充足
        dp[i] = max(dp[i],
                    dp[i - w[t[k][j]]] + c[t[k][j]]);  // 像0-1背包一样状态转移