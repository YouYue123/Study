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
    def dfs(odd_cnt: int, even_cnt: int) -> bool:
        if odd_cnt + even_cnt == 0:
            return False
        if odd_cnt + even_cnt == 1:
            return True
        if odd_cnt % 2 == 0:
            return True
        ans = False
        if even_cnt > 0:
            # return odd_cnt >= 3     
            if odd_cnt >= 3:
                return True
            ans |= not dfs(odd_cnt, 0)
            if even_cnt > 1:
                ans |= not dfs(odd_cnt, 1)
            return ans
        else:
            return odd_cnt > 3
        
    odd_cnt, even_cnt = 0, 0
    for _, num in enumerate(a):
        if num % 2 == 0:
            even_cnt += 1
        else:
            odd_cnt += 1
    # print(dfs(1, 1))
    can_win = dfs(odd_cnt, even_cnt)
    print("Moggity") if can_win else print("Larpity")

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()