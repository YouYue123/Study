import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    assert(len(a) == n)    
    if sum(a) == n:
        print(-1)
        return
    has_inner_ele = False
    for i in range(n):
        if i != 0 and i != n - 1 and a[i] > 1:
            has_inner_ele = True
    if has_inner_ele:
        print(sum(a) - 1)
    else:
        print(sum(a) - (n - 1))

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()