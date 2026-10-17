import sys
from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n, k = map(int, input().split())
    a = str(input())
    assert(len(a) == 2 * n)
    


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()