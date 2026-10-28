import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf,sqrt
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    x, y, _ = map(int, input().split())
    mid = min(x, y)
    a_x, a_y, b_x, b_y = 0, 0, mid, mid
    c_x, c_y, d_x, d_y = mid, 0, 0, mid
    # def get_dist(x_1: int, y_1: int, x_2: int, y_2: int) -> float:
    #    return sqrt((y_2 - y_1) * (y_2 - y_1) + (x_2 - x_1) * (x_2 - x_1))
    # print(get_dist(a_x, a_y, b_x, b_y))
    # print(get_dist(c_x, c_y, d_x, d_y))
    print(*[a_x, a_y, b_x, b_y])
    print(*[c_x, c_y, d_x, d_y])


def main():
    T = int(input())
    for _ in range(T):
        solve()

main()