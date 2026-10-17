import sys
from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n = int(input().rstrip())
    a = list(map(int, input().split()))
    assert(len(a) == n)
    # x + (x - pos) == m
    # 2x - pos == m
    # 2x - m = pos
    # m = 0, m = 10, m = -6, 
    # 2x + 6 = pos, x = -3
    m = 0
    for i in range(n - 1, -1, -1):
        m = 2 * a[i] - m
    ans = m // 2
    print(ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()