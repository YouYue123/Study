import sys
from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n = int(input().rstrip())
    a = list(map(int, input().split()))
    assert(len(a) == n)
    # 5
    # 3 -5 1 -4 2
    # 3 -8 -4 -13 24
    min_presum = 0
    max_presum = 0
    ans = -inf
    for i in range(n):
        # min_a = a[i] + min(min_presum, -min_presum, max_presum, -max_presum, 0)
        max_a = a[i] + max(min_presum, -min_presum, max_presum, -max_presum, 0)
        ans = max(ans, max_a)
        # min_presum += min_a
        # tmp = min_presum
        min_presum = min_presum + a[i] + min(min_presum, -min_presum, 0)
        max_presum = max_presum + a[i] + max(max_presum, -max_presum, 0)
        # print("a[i]",a[i], "min_a", min_a, "max_a", max_a)
        # print("min_presum", min_presum, "max_presum", max_presum)
    # -4 1 4 0
    # -4 (-3, 5) (-3, 11)
    
    print(ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()