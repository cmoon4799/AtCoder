


N, X = map(int, input().split())
A = list(map(int, input().split()))

for num in A:
    if num < X:
        print(1)
        X = num
    else:
        print(0)