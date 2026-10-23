import sys
from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n = int(input())
    # print("n", n)
    left, right = 0, n
    def is_valid(x: int) -> bool:
        cnt = 0
        for cur in range(x, 1, -1):
            cnt += cur * (x // cur)
        left_for_1 = n - cnt
        # print("x", x, "total", total, "left_for_1", n - total)
        return left_for_1 <= x 
    while left + 1 < right:
        mid = left + (right - left) // 2
        if is_valid(mid):
            right = mid
        else:
            left = mid
    print(right)
    ans = []
    cur = 1
    for f in range(right, 0, -1):
        for _ in range(right // f):
            ans.extend([cur] * f)
            cur += 1
        if len(ans) >= n:
            break
    # print(len(ans))
    print(*ans[:n])

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()