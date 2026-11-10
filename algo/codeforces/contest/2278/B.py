import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    x, y, z = map(int, input().split())
    # R S P
    # 0 0 3
    # 1 1 2
    candidate = " "
    if x >= y:
        candidate = "P"
    elif y >= z:
        candidate = "R"
    elif z >= x:
        candidate = "S"
    
    ans = candidate * (x + y + z)
    print(ans)


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()