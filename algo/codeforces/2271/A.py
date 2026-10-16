import sys
from collections import defaultdict
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    a, b = map(int, input().split())
    # 0, 0
    # 1, -1<= y <=1
    # 2, -2 <= y <= 2
    if abs(b) - a > 1:
        print(-1)
        return
    print(a + (0 if a % 2 == b % 2 else 1))

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()