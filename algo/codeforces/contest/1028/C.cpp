#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <limits>
#include <functional>
#include <deque>
#include <unordered_set>
#include <map>
using namespace std;
using ll = long long; // 使用long long类型别名

static const int MAXA = 5000; // 定义最大可能的数值

// 计算两个数的最大公约数（GCD）
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;         // 输入数组长度
    vector<int> a(n); // 定义数组a
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // 输入数组a
    }

    // 计算数组a中所有元素的GCD
    int g = a[0];
    for (int i = 1; i < n; i++)
    {
        g = gcd(g, a[i]);
    }

    // 统计数组中等于g的元素个数
    int cnt_g = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == g)
            cnt_g++;
    }

    // 如果数组中存在g，则直接输出结果
    if (cnt_g > 0)
    {
        cout << (n - cnt_g) << endl;
        return;
    }

    // 如果数组中不存在g，则进行进一步处理
    vector<int> b(n); // 定义数组b，存储a[i] / g
    int maxB = 0;     // 记录数组b中的最大值
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] / g;
        maxB = max(maxB, b[i]);
    }

    const int MAX = n + 1;                        // 定义一个较大的数，用于初始化
    static int best[MAXA + 1], tempArr[MAXA + 1]; // 定义静态数组，用于动态规划

    // 初始化best数组，best[d]表示得到d的最小操作次数
    for (int d = 1; d <= maxB; d++)
    {
        best[d] = MAX; // 初始化为较大的数
    }

    // 动态规划处理
    for (int i = 0; i < n; i++)
    {
        // 复制当前best数组到tempArr
        for (int d = 1; d <= maxB; d++)
        {
            tempArr[d] = best[d];
        }

        // 更新tempArr数组
        for (int d = 1; d <= maxB; d++)
        {
            if (best[d] < MAX) // 如果当前d可达
            {
                int d2 = gcd(d, b[i]);       // 计算新的GCD
                int candidate = best[d] + 1; // 候选操作次数
                if (candidate < tempArr[d2]) // 如果更优则更新
                {
                    tempArr[d2] = candidate;
                }
            }
        }

        // 单独处理当前元素b[i]
        if (1 < tempArr[b[i]])
        {
            tempArr[b[i]] = 1; // 直接选择当前元素，操作次数为1
        }

        // 将tempArr复制回best数组
        for (int d = 1; d <= maxB; d++)
        {
            best[d] = tempArr[d];
        }
    }

    // 计算最终结果
    int t = best[1];     // 得到1的最小操作次数
    int ans = n + t - 2; // 最终答案公式
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false); // 关闭同步，提高输入输出速度
    cin.tie(nullptr);            // 解除cin和cout的绑定

    int T;
    cin >> T; // 输入测试用例数量
    while (T--)
    {
        solve(); // 处理每个测试用例
    }
    return 0;
}