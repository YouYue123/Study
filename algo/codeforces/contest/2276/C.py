import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    cnt = [0] * k
    cur_sum, pre_sum, ans, left = 0, 0, 0, 0
    for right in range(n):
        cur_sum += a[right]
        if cnt[0] == 0 and right - left + 1 > k:
            cnt[0] = 1
        if right - left > k:
            pre_sum += a[left]
            cnt[pre_sum % k] += 1
            left += 1
        t = cur_sum % k
        ans += cnt[t]
    print(ans)


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()