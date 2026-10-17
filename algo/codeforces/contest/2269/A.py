import sys

input = sys.stdin.readline
INF = float('inf')
out = []


def solve():
    n, k = map(int, input().split())
    ans = pow(2, (n - k + 1)) + (k - 1) * 2
    print(ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()


main()