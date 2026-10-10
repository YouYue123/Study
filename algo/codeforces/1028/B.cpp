
#include <iostream>
#include <vector>
using namespace std;
using ll = long long; // 使用long long类型别名

const int MOD = 998244353; // 定义模数

void solve()
{
    int n;
    cin >> n;               // 输入数组长度
    vector<int> p(n), q(n); // 定义两个数组p和q
    for (int i = 0; i < n; i++)
    {
        cin >> p[i]; // 输入数组p
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i]; // 输入数组q
    }

    // idxP[x]表示数字x在p数组中的位置，idxQ同理
    vector<int> idxP(n), idxQ(n);
    for (int i = 0; i < n; i++)
    {
        idxP[p[i]] = i;
        idxQ[q[i]] = i;
    }

    // 预处理2的幂次数组，pow2[i] = 2^i mod MOD
    vector<int> pow2(n);
    pow2[0] = 1; // 2^0 = 1
    for (int i = 1; i < n; i++)
    {
        pow2[i] = (int)((ll)pow2[i - 1] * 2 % MOD); // 计算并取模
    }

    vector<int> r(n, 0); // 结果数组
    int prefixMaxP = -1; // p数组的前缀最大值
    int prefixMaxQ = -1; // q数组的前缀最大值

    for (int i = 0; i < n; i++)
    {
        // 更新p和q的前缀最大值
        if (p[i] > prefixMaxP)
            prefixMaxP = p[i];
        if (q[i] > prefixMaxQ)
            prefixMaxQ = q[i];

        // M是当前p和q前缀最大值的较大者
        int M = max(prefixMaxP, prefixMaxQ);

        // 获取M在p和q中的位置
        int posP = idxP[M];
        int posQ = idxQ[M];

        int mBest = -1; // 用于记录最佳的m值

        // 情况1：检查是否可以通过p数组的某个位置jP来形成有效的m
        if (posP <= i)
        {
            int jP = posP;
            int otherQ = q[i - jP];  // 对应的q数组中的值
            int mP = min(M, otherQ); // 计算m值
            if (mP > mBest)
                mBest = mP; // 更新最佳m值
        }
        // 情况2：检查是否可以通过q数组的某个位置jQ来形成有效的m
        if (posQ <= i)
        {
            int jQ = i - posQ;
            int otherP = p[jQ];      // 对应的p数组中的值
            int mQ = min(otherP, M); // 计算m值
            if (mQ > mBest)
                mBest = mQ; // 更新最佳m值
        }

        // 计算结果：r[i] = (2^M + 2^mBest) mod MOD
        ll sumMod = (ll)pow2[M] + pow2[mBest];
        r[i] = (int)(sumMod % MOD);
    }

    // 输出结果数组
    for (int i = 0; i < n; i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
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