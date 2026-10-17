import sys
from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n = int(input())
    x = 1
    while x <= n:
        x *= 2
    x //= 2
    presum: list[int] = []
    presum.extend(list(range(x))) # [0, x-1]
    presum.extend(list(range(x - 1, -1, -1))) # [x-1, 0]
    presum.extend(list(range(x, 2 * x))) # [x, 2x-1]
    presum.extend(list(range(2 * x - 1, x - 1, -1))) # [2x-1, x]
    # print(presum)
    ans: list[int] = []
    for i in range(1, len(presum)):
        ans.append(presum[i] ^ presum[i - 1])
    print(len(ans))
    print(*ans)
    

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()