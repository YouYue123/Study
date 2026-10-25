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
    assert(len(a) == n)
    cnt = Counter(a)
    ans, acc = 0, 0
    while True:
        acc += cnt[ans]
        if acc >= k and cnt[ans] != 0:
            acc -= k
            ans += 1
        else:
            break
    print(ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()