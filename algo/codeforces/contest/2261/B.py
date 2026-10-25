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
    def get_highest_bit(num : int):
        # zero-based
        ans = -1
        cur = num
        while cur > 0:
            ans += 1
            cur >>= 1
        return ans
    # print(get_highest_bit(1))
    ans = 0
    high_bit_pos = -1
    for idx, cur_num in enumerate(a):
        if idx < n - 1 and cur_num != a[idx + 1]:
            high_bit_pos = max(
                high_bit_pos,
                get_highest_bit(abs(cur_num - a[idx + 1]))
            )
        ans |= cur_num
    # print(high_bit_pos)
    for i in range(high_bit_pos, -1, -1):
        ans |= (1 << i)
    print(ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()