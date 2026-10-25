import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n = int(input())
    s = str(input()).rstrip()
    assert(len(s) == n)
    min_num, max_num = inf, -1
    cnt = 0
    for i in range(n):
        if s[i] == "1":
            cnt += 1
            min_num = min(min_num, i)
            max_num = max(max_num, i)
    if cnt > 2:
        print(max_num - min_num)
    elif cnt < 2:
        print(0)
    else:
        print(1)

    


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()