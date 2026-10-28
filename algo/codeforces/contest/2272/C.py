import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    assert(n >= 2 and x >= 0)
    assert(len(a) == n)
    # 0 6 8 10 13 14 16 19 25 31
    #  3                  22 28
    def is_isolate (i: int, mid: int) -> bool:
        if i == 0:
            return a[i + 1] - a[i] > mid
        if i == n - 1:
            return a[i] - a[i - 1] > mid
        return a[i] - a[i - 1] > mid and a[i + 1] - a[i] > mid  
    def is_valid(mid: int) -> bool:
        isolate_cnt, mergable_cnt = 0, 0
        used = False
        for i in range(n):
            if is_isolate(i, mid):
                isolate_cnt += 1
                if not used and i > 0 and is_isolate(i - 1, mid) and a[i] - a[i - 1] <= 2 * mid:
                    mergable_cnt += 1
                    used = True
                    continue
            used = False
        # print("isolate_cnt", isolate_cnt, "mergable_cnt", mergable_cnt)
        return isolate_cnt - mergable_cnt <= x
    # print(is_valid(3))
    left, right = 0, a[-1] - a[0]
    while left + 1 < right:
        mid = left + (right - left) // 2
        if is_valid(mid):
            right = mid
        else:
            left = mid
    print(right)


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()