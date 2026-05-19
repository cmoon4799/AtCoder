import sys
from bisect import bisect_left, bisect_right
from collections import defaultdict, Counter
input = sys.stdin.readline

N, M = map(int, input().split())
INF = 10**9

# if there is a cloth that covers the exact range
# 1. there is another cloth that covers the exact range
# 2. there is a cloth contained in [L + 1, R]; need minimum right end among cloths that start on or after L + 1
# 3. there is a cloth contained in [L, R - 1]

# if there are no cloths that cover the exact range
# among cloths who end on R, choose the minimum left end >= L
# among cloths who start on L, choose maximum right end <= R


left_ends = defaultdict(list)
right_ends = defaultdict(list)
min_by_l = [INF for _ in range(N + 2)]
min_right_end = [INF for _ in range(N + 3)]

cloth_counts = Counter()
for _ in range(M):
    L, R = map(int, input().split())
    cloth_counts[(L, R)] += 1
    left_ends[R].append(L)
    right_ends[L].append(R)
    min_by_l[L] = min(min_by_l[L], R)

for val in left_ends.values():
    val.sort()
for val in right_ends.values():
    val.sort()

for left in range(N + 1, -1, -1):
    min_right_end[left] = min(min_right_end[left + 1], min_by_l[left])

Q = int(input())
res = []
for _ in range(Q):
    L, R = map(int, input().split())
    if cloth_counts[(L, R)] > 0:
        if cloth_counts[(L, R)] > 1:
            res.append(True)
        else:
            if min_right_end[L + 1] <= R or min_right_end[L] <= R - 1:
                res.append(True)
            else:
                res.append(False)
    else:
        pos_r = bisect_right(right_ends[L], R) - 1
        pos_l = bisect_left(left_ends[R], L)

        if pos_r >= 0 and pos_l < len(left_ends[R]) and left_ends[R][pos_l] <= right_ends[L][pos_r] + 1:
            res.append(True)
        else:
            res.append(False)

for v in res:
    print("Yes" if v else "No")
