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
    if n == 1:
        print(1)
        return
    if n == 2:
        print(a[1] - a[0])
        return
    
    # def is_isolate(i : int, mid: int) -> bool:
    #     if i == 0:
    #         return i + 1 == n or a[i + 1] - a[i] > mid
    #     if i == n - 1:
    #         return i == 0 or a[i] - a[i - 1] > mid
    #     return a[i + 1] - a[i] > mid or a[i] - a[i - 1] > mid
    def is_valid(mid: int) -> bool:
        i = 0
        cnt = 0
        while i < n:
            if i + 1 < n:
                if a[i + 1] - a[i] > mid:
                    cnt += 1
                    i += 1
                else:
                    i += 2
            else:
                cnt += 1
                i += 1
            
        return cnt <= 1

    left, right = 0, a[-1] - a[0] + 1
    while left + 1 < right:
        mid = left + (right - left) // 2
        if is_valid(mid):
            right = mid
        else:
            left = mid
    print(right)    
    # diff = []
    # for i in range(n):
    #     diff.append(a[i] - a[i - 1])
    # diff.sort()
    # print(diff[-2])
def main():
    T = int(input())
    for _ in range(T):
        solve()

main()