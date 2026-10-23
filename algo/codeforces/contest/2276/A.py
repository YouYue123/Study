import sys
from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf, gcd

input = sys.stdin.readline
MOD = 10 ** 9 + 7

cnt = 0
def solve():
    a, b = map(int, input().split())
    # k sandwidth
    if a <= b:
        print(-1)
        return 
    print(min(a - b, b))



def main():
    T = int(input())
    for _ in range(T):
        global cnt
        cnt += 1
        solve()

main()