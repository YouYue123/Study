import sys
from collections import Counter

input = sys.stdin.readline

def solve():
    input()
    a = list(map(int, input().split()))
    CYCLE = [4, 16, 37, 58, 89, 145, 42, 20]
    POS = {v: i for i, v in enumerate(CYCLE)}
    def get_nxt(x: int) -> int:
        s = 0
        while x:
            d = x % 10
            s += d * d
            x //= 10
        return s
    key_memo = {}
    def get_key(x: int) -> int:
        if x in key_memo:
            return key_memo[x]
        num, t = x, 0
        while num != 1 and num not in POS:
            num = get_nxt(num)
            t += 1
        k = -1 if num == 1 else (POS[num] - t) % 8
        key_memo[x] = k
        return k
    cnt = Counter(get_key(x) for x in a)
    ans = 0
    for c in cnt.values():
        ans += c * (c - 1) // 2
    print(ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()