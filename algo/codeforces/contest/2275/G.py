import sys
from itertools import accumulate

input = sys.stdin.readline
INF = float('inf')
out = []

class UF:
    parent: list[int]
    size: list[int]
    cnt: int
    def __init__(self, n : int):
        self.parent = list(range(n))
        self.size = [1] * n
        self.cnt = n
    def unite(self, x: int, y: int):
        parent_x = self._find_parent(x)
        parent_y = self._find_parent(y)
        if parent_x == parent_y:
            return
        if self.size[parent_x] > self.size[parent_y]:
            self.parent[parent_y] = parent_x
            self.size[parent_x] += self.size[parent_y]
        else:
            self.parent[parent_x] = parent_y
            self.size[parent_y] += self.size[parent_x]
        self.cnt -= 1

    def _find_parent(self, x: int):
        if x == self.parent[x]:
            return x
        self.parent[x] = self._find_parent(self.parent[x])
        return self.parent[x]

    def is_connect(self, x: int, y: int):
        return self._find_parent(x) == self._find_parent(y)

def solve():
    n, m, _ = map(int, input().split())
    g = []
    uf = UF(n)
    for _ in range(m):
        u, v, d = map(int, input().split())
        u -= 1
        v -= 1
        g.append((d, u, v))
    x = list(map(int, input().split()))
    g.sort()
    base_profit = 0
    vals = []
    for d, u, v in g:
        if uf.is_connect(u, v):
            base_profit += d
        else:
            uf.unite(u, v)
            vals.append(d)
    vals.reverse()
    presum = list(accumulate(vals, initial=0))
        # print(presum[i + 1])
    # print(vals)
    # print("uf.cnt:", uf.cnt)
    required_con = uf.cnt - 1
    # print("required_con: ", required_con)
    ans: list[int] = []
    def is_valid(t: int) -> bool:
        return vals[t] >= ((t + required_con + 1) * base_cost)
    for base_cost in x:
        cur = base_profit
        cur -= base_cost * (1 + required_con) * required_con // 2
        # cur_f = required_con + 1
        # for i in range(len(vals)):
        #     if cur_f * base_cost > vals[i]:
        #         print("end at:", i) 
        #         break
        #     cur += vals[i] - cur_f * base_cost
        #     cur_f += 1
        left  = -1
        right = len(vals)
        while left + 1 < right:
            mid = left + (right - left) // 2
            if is_valid(mid):
                left = mid
            else:
                right = mid
        # print("right:", right)
        cur += presum[right] - base_cost * (required_con + right + required_con + 1) * right // 2
        ans.append(cur)
    print(*ans)
        
    # 5 4 1
    # 1 2 5 -> 1 2 4 -> 1 profit
    # 1 3 5 -> 1 3 3 -> 2 profit
    # 1 4 5 -> 1 4 2 -> 3 profit
    # 1 5 5 -> 1 5 1 -> 4 profit
    # 1
    # 5 4 3
    # 1 2 5
    # 2 3 5
    # 3 4 5
    # 1 3 1
    # 1 3 10

def main():
    T = int(input())
    for _ in range(T):
        solve()


main()