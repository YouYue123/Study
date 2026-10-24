import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    s = str(input()).rstrip()
    assert(len(s) >= 3)
    # 001011010
    same_cnted = False
    diff_cnted = False
    ans = 1
    for i in range(1, len(s) - 1):
        is_diff_from_both = s[i] != s[i + 1] and s[i] != s[i - 1]
        is_same_as_both = s[i] == s[i + 1] and s[i] == s[i - 1]
        if is_same_as_both:
            same_cnted = True
        if is_diff_from_both:
            diff_cnted = True
    ans += same_cnted + diff_cnted
    print(ans)
    


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()