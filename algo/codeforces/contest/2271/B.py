import sys
from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7


def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    # 2 * k - 1 
    counter = Counter(a)
    max_elem = max(a)
    alice_win = False
    for num in range(max_elem + 1):
        if counter[num] < 2 * k - 1:
            break
        if counter[num] == 2 * k - 1:
            alice_win = True
            break
    print("YES") if alice_win else print("NO")

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()