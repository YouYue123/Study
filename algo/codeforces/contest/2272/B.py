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
    l_1 = input().rstrip()
    l_2 = input().rstrip()
    assert(len(l_1) == len(l_2) and len(l_1) == n)
    cnt = 0
    for i in range(n):
        if l_1[i] == 'f':
            cnt += 1
        if l_2[i] == 'f':
            cnt += 1
    print(cnt % 2)
    # fo
    # of
    # fo
    # of
    # fff
    # ofo
    # i = 0
    # ans = 0
    # while i < n:
    #     if (l_1[i] == 'f' and l_2[i] == 'o') or (l_2[i] == 'f' and l_1[i] == 'o'):
    #         if i + 1 == n or (l_1[i + 1] == 'o' and l_2[i + 1] == 'o'):
    #             ans += 1
    #         i += 2
    #     else:
    #         i += 1
    # print(ans)
def main():
    T = int(input())
    for _ in range(T):
        solve()

main()