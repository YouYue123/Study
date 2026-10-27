import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    assert(len(a) == n)
    # kth largest max is n - k + 1
    # 3 2
    # 2 0 1
    # 0 1 3
    # 1 0 2
    def get_kth_mex():
        cur_mex = 0
        tmp = []
        cur_set = set()
        for i in range(n):
            cur_set.add(a[i])
            while cur_mex in cur_set:
                cur_mex += 1
            tmp.append(cur_mex)
        tmp.sort()
        return tmp[-k]
    ans = (get_kth_mex(), -1, -1)
    for i in range(n):
        for j in range(i + 1, n):
            a[i], a[j] = a[j], a[i]
            kth_mex = get_kth_mex()
            if kth_mex > ans[0]:
                ans = (kth_mex, i, j)
            a[i], a[j] = a[j], a[i]
    if ans[1] == -1:
        print(-1)
    else:
        print(*[ans[1] + 1, ans[2] + 1])

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()