import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    assert(len(a) == n)
    # n - 1
    ans = 0
    for _, num in enumerate(a):
        if num == 0 or num < n:
            ans = n
            break
            
    print(ans)
        

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()