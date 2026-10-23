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
    cap = right
    group_size, cur_cnt, cur = right, 0, 1
    ok = True
    while len(ans) < n:
        while cur_cnt + group_size <= cap:
            for _ in range(group_size):
                ans.append(cur)
                if len(ans) == n:
                    ok = False
                    break
            if not ok:
                break
            cur_cnt += group_size
            cur += 1
        if not ok:
            break  
        cur_cnt = 0
        group_size = max(group_size - 1, 1)
    # print(len(ans))
    print(*ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()