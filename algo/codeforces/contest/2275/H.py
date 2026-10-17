import sys
from collections import defaultdict
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf


input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n, m = map(int, input().split())
    matrix = [[0] * m for _ in range(n)]
    for i in range(n):
       matrix [i] = list(map(int, input().split()))
    # print(matrix)

    presum = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n):
        for j in range(m):
            presum[i + 1][j + 1] = presum[i][j + 1] + presum[i + 1][j] + matrix[i][j] - presum[i][j]
    ans = 0
    Wr = 1 if n % 2 == 0 else 0
    Wc = 1 if m % 2 == 0 else 0
    if Wc:
        for c in range(m + 1):
            wc = 1 if c % 2 == 0 else -1
            s1 = s2 = 0
            for r in range(n + 1):
                wr = 1 if r % 2 == 0 else -1
                a = presum[r][c]
                s1 += wr * a
                s2 += wr * a * a
            ans += wc * (Wr * s2 - s1 * s1)
    t1 = t2 = 0
    for r in range(n + 1):
        wr = 1 if r % 2 == 0 else -1
        L = 0
        for c in range(m + 1):
            L += presum[r][c] if c % 2 == 0 else - presum[r][c]
        t1 += wr * L
        t2 += wr * L * L
    ans -= Wr * t2 - t1 * t1
    print(ans % MOD)
    # def get_sum(x1: int, y1: int, x2: int, y2: int):
    #     return presum[x2 + 1][y2 + 1] - presum[x1][y2 + 1] - presum[x2 + 1][y1] + presum[x1][y1]
    # (-1)^(a+b) = (-1)^r1 · (-1)^r2 · (-1)^c1 · (-1)^c2
    # ans = 0
    # for i in range(n):
    #     for j in range(m):
    #         for p in range(i, n):
    #             for q in range(j, m):
    #                 a = p - i + 1
    #                 b = q - j + 1
    #                 cur_sum = get_sum(i, j, p, q)
    #                 sign = -1 if (a + b) % 2 == 1 else 1
    #                 ans += cur_sum * cur_sum * sign

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()