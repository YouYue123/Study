from functools import lru_cache
import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType
# def bootstrap(f, stack=[]):
#     def wrappedfunc(*args, **kwargs):
#         if stack:
#             return f(*args, **kwargs)
#         to = f(*args, **kwargs)
#         while True:
#             if type(to) is GeneratorType:
#                 stack.append(to)
#                 to = next(to)
#             else:
#                 stack.pop()
#                 if not stack:
#                     break
#                 to = stack[-1].send(to)
#         return to
#     return wrappedfunc

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    # 1 - 2 - 3 - 7 
    # | ~  |
    # |  ~ 4 - 5
    # |   ~ ~ ~    
    # 6 
    n, m = map(int, input().split())
    tree = defaultdict(list[int])
    for _ in range(n - 1):
        x, y = map(int, input().split())
        tree[x].append(y)
        tree[y].append(x)
    a = list(map(int, input().split()))
    assert(len(a) == m)   
    for i in range(m):
        tree[1].append(a[i])
        tree[a[i]].append(1)
    # print(tree)
    visit = set[int]()
    q = deque()
    q.append((n, 0))
    visit.add(n)
    ans = 0
    while q:
        cur, d = q.popleft()
        for _, nxt in enumerate(tree[cur]):
            if nxt == 1:
                ans = max(ans, d + 1)
            if nxt == 1 or nxt in visit:
                continue
            visit.add(nxt)
            q.append((nxt, d + 1))
    print(ans)
    # memo = defaultdict(int)
    # @bootstrap
    # def dfs(cur: int):
    #     if cur == n:
    #         yield 0
    #     if cur in visit:
    #         yield -inf
    #     if cur in memo:
    #         yield memo[cur]
    #     visit.add(cur)
    #     ans = -inf
    #     for _, nxt in enumerate(tree[cur]):
    #         if nxt not in visit:
    #             ans = max(ans, 1 + (yield dfs(nxt)))
    #     # visit.remove(cur)
    #     if ans != -inf:
    #         memo[cur] = ans
    #     yield ans
    # dfs(n)
def main():
    T = int(input())
    for _ in range(T):
        solve()

main()