from operator import is_
import sys
from collections import defaultdict
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
from itertools import pairwise
from math import inf

input = sys.stdin.readline
MOD = 10 ** 9 + 7
# 011
# 101
    
# a_i -> ai xor (3 * k)  
# a_i+1 -> ai xor (3 * k)
# 1 <= k <= 5
# a_i < 16
# 10 3
# 1010  011
# 0 3 6 9 12 15
# 0000
# 0011 
# 0110 
# 1001 
# 1100
# 1111
# 2 3 5
# 010
# 011
# 101
def solve():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    ans = []
    def pop_cnt (x: int):
        tmp = 0
        while x > 0:
            tmp += x % 2
            x //= 2
        return tmp

    cur_ans = 0
    for i in range(n):
        # print(a[i], "pop_cnt", pop_cnt(a[i]))
        if pop_cnt(a[i]) % 2 == 0:
            cur_ans += 1
    ans.append(cur_ans)

    for _ in range(q):
        p, x = map(int, input().split())
        p -= 1
        pre = ans[-1]
        is_pre_valid = pop_cnt(a[p]) % 2 == 0
        is_pos_valid = pop_cnt(x) % 2 == 0
        a[p] = x
        if is_pre_valid and not is_pos_valid:
            ans.append(pre - 1)
        elif not is_pre_valid and is_pos_valid:
            ans.append(pre + 1)
        else:
            ans.append(pre)
    print(*ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()