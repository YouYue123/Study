import sys
from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n, k = map(int, input().split())
    a = str(input().rstrip())
    assert(len(a) == 2 * n)
    # 3 2
    # 101110
    # 011101
    # 7 4
    # 10011110101011
    # 01011101010111
    ans = [0, 0]
    for i in range(2 * n):
        nxt = (i + 1) % (2 * n)
        if a[i] == '1': 
            if a[nxt] == '0':
                ans[(nxt + 1) % 2] += 1
            else:
                ans[(i + 1) % 2] += 1
    print(*ans)


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()