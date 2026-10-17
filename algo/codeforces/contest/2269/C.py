import sys
from collections import defaultdict
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    ops = n - k + 1
    p = min(k - 1, ops)
    # print(p)
    for i in range(p):
        # print("a[i]", a[i], "a[n - i - 1]", a[n - i - 1])
        ans += max(a[i], a[n - i - 1])
    # print("p", p, "n-p", n-p)
    if ops > p:
        ans += sum(a[p : n - p])
    print(ans)
def main():
    T = int(input())
    for _ in range(T):
        solve()

main()