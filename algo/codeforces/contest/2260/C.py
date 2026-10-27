import sys
from collections import defaultdict, Counter, deque
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf
from types import GeneratorType

input = sys.stdin.readline
MOD = 10 ** 9 + 7

def solve():
    x, y = map(int, input().split())
    # a = x ^ y
    # a + b = (a ⊕ b) + 2 · (a & b)
    # b = (x - 1) ^ (y + 1) if x >= 1 else 0
    # d = 1 ^ (y + x - 1) if y + x >= 1 else 0
    # if a >= b and a >= c and a >= d:
    #     ans = (a, 0)
    # elif b >= a and b >= c and b >= d:
    #     ans = (b, 1)
    # elif c >= a and c >= b and c >= d:
    #     ans = (c, x)
    # elif d >= a and d >= b and d >= c:
    #     ans = (d, x - 1)
    # 5 5
    # 111 1000
    max_ele = x + y    
    def get_target():
        # print(b_max_ele)
        cur = max_ele.bit_length() - 1
        candidate, now = 0, 0
        while cur >= 0:
            if (max_ele >> cur) & 1 == 1:
                if (y >> cur) & 1 == 1:
                    now += (1 << cur)
                else:
                    candidate = now + (1 << cur)
            else:
                if (y >> cur) & 1 == 1:
                    return candidate
            cur -= 1
        return now
    min_time = get_target() - y
    # if x ^ y == x + y:
    #     min_time = 0
    # else:
    #     t_0 = 1 << (max(x, y).bit_length())
    #     t_1 = t_0 + 1
    #     # print("t_0", t_0, "t_1", t_1)
    #     with_t0 = t_0 ^ (x - (t_0 - y))
    #     # print("with t_0", with_t0)
    #     if x + y > with_t0:
    #         min_time = t_1 - y
    #     else:
    #         min_time = t_0 - y
    #     # if x + y <= t_1:

    #     #     min_time = y - t_0
    #     # if t_1 < x:
    #     #     min_time 
    print(*[max_ele, min_time])
    # while x > 0:
    #     x -= 1
    #     y += 1
    #     print("x", x, "y", y, "x^y", x ^ y)
    

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()