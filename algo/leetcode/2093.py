from collections import defaultdict
from heapq import heappop, heappush
from math import inf


class Solution:
    def minimumCost(self, n: int, highways: list[list[int]], discounts: int) -> int:
        g = defaultdict(list)
        for h in highways:
            u, v, t = h
            g[u].append((v, t))
            g[v].append((u, t))
        
        dist = []
        for _ in range(n):
            dist.append([inf] * (discounts + 1))
        # print(dist)
        pq = []
        heappush(pq, (0, 0, discounts))
        while len(pq) > 0:
            cur_t, u, cur_discount = heappop(pq)
            # print(cur_t, u, cur_discount)
            if dist[u][cur_discount] < cur_t:
                continue
            for v, t in g[u]:
                if dist[v][cur_discount] > t + cur_t:
                    dist[v][cur_discount] = t + cur_t
                    heappush(pq, (t + cur_t, v, cur_discount))
                if cur_discount > 0 and dist[v][cur_discount - 1] > t // 2 + cur_t:
                    dist[v][cur_discount - 1] = t // 2 + cur_t
                    heappush(pq, (t // 2 + cur_t, v, cur_discount - 1))
        ans = inf
        for item in dist[n - 1]:
            ans = min(ans, item)
        return ans if ans != inf else -1
        # def dfs(u, remain) -> int:
        #     if u == n - 1:
        #         return 0
        #     visit[u] = True
        #     cur_ans = math.inf
        #     for v, toll in g[u]:
        #         if visit[v]:
        #             continue
        #         cur_ans = min(cur_ans, dfs(v, remain) + toll)
        #         if remain >= 1:
        #             cur_ans = min(cur_ans, dfs(v, remain - 1) + toll // 2)
        #     visit[u] = False
        #     return cur_ans
        
        # ans = dfs(0, discounts)
        # return ans if ans != math.inf else -1
