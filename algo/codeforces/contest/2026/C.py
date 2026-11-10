import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    n = int(input())
    s = input().rstrip()
    assert(len(s) == n)
    # 0101010101
    # 6
    # 101101
    # 1 + 2 + 3 + 4
    # 7
    # 1111111
    # 


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()