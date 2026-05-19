import sys
from bisect import bisect_left
input = sys.stdin.readline

N = int(input())
a = []
for _ in range(N):
    t, x = map(int, input().split())
    a.append((t + x, t - x))
a.sort()

ls = []  # longest sequence
for i in range(N):
    v = -a[i][1]
    if len(ls) == 0 or v > ls[-1]:
        ls.append(v)
    else:
        ls[bisect_left(ls, v)] = v

print(len(ls))
