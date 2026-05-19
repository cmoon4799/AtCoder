import sys


input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))
flatten = {}
for i, n in enumerate(A):
    if n not in flatten:
        flatten[n] = len(flatten)
    A[i] = flatten[n]
        
E = [[] for _ in range(N)]
for i in range(N - 1):
    u, v = map(int, input().split())
    E[u - 1].append(v - 1)
    E[v - 1].append(u - 1)


res = [False for _ in range(N)]
st = [(0, -1, True)] # boolean represents Enter or Exit
count = [0 for _ in range(N)]
duplicate_count = 0
while st:
    u, p, eox = st.pop()
    if eox:
        st.append((u, p, False))
        count[A[u]] += 1
        if count[A[u]] == 2:
            duplicate_count += 1
        if duplicate_count > 0:
            res[u] = True
        
        for v in E[u]:
            if v == p:
                continue
            st.append((v, u, True))
    else:
        count[A[u]] -= 1
        if count[A[u]] == 1:
            duplicate_count -= 1

for r in res:
    print("Yes" if r else "No")