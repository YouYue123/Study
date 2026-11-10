# 看到	想到
# "能否重排成回文"	只看奇偶 → 26-bit mask，m & (m-1) == 0
# 树上路径查询	前缀（root→x）+ LCA 抵消
# 修改一个点，影响整棵子树	Euler tour，子树 = [tin, tout] 区间
# 区间修改 + 单点查询	差分 + BIT
# 运算是 XOR	自己就是逆运算，抵消关系最简单
class BIT:
    # XOR 版 Fenwick：单点 XOR，前缀 XOR 查询（1-indexed）
    def __init__(self, n):
        self.n = n
        self.t = [0] * (n + 1)

    def update(self, i, x):
        while i <= self.n:
            self.t[i] ^= x
            i += i & -i

    def query(self, i):
        r = 0
        while i > 0:
            r ^= self.t[i]
            i -= i & -i
        return r


class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str, queries: list[str]) -> list[bool]:
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        # ---- Step 6: 迭代 DFS，求 parent / depth / tin / tout ----
        parent = [0] * n          # root(0) 的 parent 设为自己
        depth = [0] * n
        tin = [0] * n
        tout = [0] * n
        timer = 0
        stack = [(0, False)]
        while stack:
            v, leaving = stack.pop()
            if leaving:
                tout[v] = timer   # 子树里最大的 tin
                continue
            timer += 1
            tin[v] = timer        # 1-indexed，方便 BIT
            stack.append((v, True))
            for w in g[v]:
                if w != parent[v]:
                    parent[w] = v
                    depth[w] = depth[v] + 1
                    stack.append((w, False))

        # ---- Step 5: binary lifting 表 ----
        LOG = max(1, n.bit_length())
        up = [parent[:]]
        for _ in range(1, LOG):
            prev = up[-1]
            up.append([prev[prev[v]] for v in range(n)])

        def lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u
            diff = depth[u] - depth[v]
            k = 0
            while diff:                       # 把 u 抬到和 v 同一层
                if diff & 1:
                    u = up[k][u]
                diff >>= 1
                k += 1
            if u == v:
                return u
            for k in range(LOG - 1, -1, -1):  # 不相等才跳，保持在 lca 下方
                if up[k][u] != up[k][v]:
                    u = up[k][u]
                    v = up[k][v]
            return up[0][u]

        # ---- Step 3+4: Euler tour 区间 + 差分 BIT ----
        bit = BIT(n)

        def subtree_xor(v, x):                # v 的整棵子树都 XOR x
            bit.update(tin[v], x)
            bit.update(tout[v] + 1, x)

        def P(v):                             # root→v 的前缀 XOR
            return bit.query(tin[v])

        cur = list(s)
        for v in range(n):                    # 初始化 = 每个点对自己的子树做一次 update
            subtree_xor(v, 1 << (ord(cur[v]) - 97))

        # ---- 处理 queries ----
        ans = []
        for q in queries:
            parts = q.split()
            if parts[0] == "update":
                u, c = int(parts[1]), parts[2]
                if cur[u] != c:
                    delta = (1 << (ord(cur[u]) - 97)) ^ (1 << (ord(c) - 97))
                    subtree_xor(u, delta)
                    cur[u] = c                # 记得同步，下次要用旧字母
            else:
                u, v = int(parts[1]), int(parts[2])
                a = lca(u, v)
                m = P(u) ^ P(v) ^ (1 << (ord(cur[a]) - 97))   # Step 2 的公式
                ans.append(m & (m - 1) == 0)                   # Step 1：最多一个奇数
        return ans