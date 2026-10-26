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
    a = list(map(int, input().split()))
    assert(len(a) == n)
    cnt = 0
    valid = 0
    for i in range(n):
        if a[i] == 0:
            if i == 0 or i == n - 1:
                valid += 1
            cnt += 1
        
    if cnt < 2:
        print(-1)
        return
    print(2 - valid)


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()