import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    x, y, k = map(int, input().split())
    # print(x, y, k)
    ans = 0
    # y % x + (y + 1) % (x + 1) + ... (y + x) % (2 * x) + ... (y + y) % (x + y) + ... (y + k) % (x + k)
    # y - x never change
    # 5 % 3 + 6 % 4 + 7 % 5 + 8 % 6
    # 5 % 1 + 6 % 2 + 7 % 3 + 8 % 4 + 9 % 5
    # 9 % 3 + 10 % 4 + 11 % 5 + 12 % 6 + 13 % 7 + 14 % 8
    # 0 + 2 + 1 + 0 + 6 + 6
    # 1 999900 
    # 999900 % 1 + 999901 % 2  + 999902 % 3
    for i in range(k):
        cur = y % x
        if cur == y - x:
            # print("break!", "i", i, "cur", cur)
            ans += (k - i) * cur 
            break
        ans += cur
        # prev = cur
        x += 1
        y += 1
    print(ans)


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()