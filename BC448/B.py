

N, M = map(int, input().split())
C = list(map(int, input().split()))
A, B = [], []
for _ in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

t = [0 for _ in range(1005)]
for i in range(N):
    t[A[i] - 1] += B[i]

res = 0
for i in range(M):
    res += min(C[i], t[i])

print(res)