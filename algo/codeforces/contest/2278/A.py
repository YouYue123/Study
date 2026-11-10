import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    n, m  = map(int, input().split())
    p: str = input().strip()
    q: str = input().strip()
    assert(len(p) == n)
    assert(len(q) == m)
    cnt_p, cnt_q = Counter(p), Counter(q)
    for key in cnt_p:
        while cnt_p[key] > 0 and cnt_q[key] > 0:
            cnt_p[key] -= 1
            cnt_q[key] -= 1
    must = ["s", "i", "x"]
    ok = True
    for c in must:
        if cnt_p[c] != 1:
            ok = False
    for i in range(26):
        c = chr(i + ord("a"))
        if cnt_q[c] != 0:
            ok = False
        if c in must:
            continue
        if cnt_p[c] != 0:
            ok = False
    print("YES" if ok else "NO")
    # print(cnt_p)
    # print(cnt_q)


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()