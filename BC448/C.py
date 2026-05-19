N, Q = map(int, input().split())
A = list(map(int, input().split()))

smallest = sorted((a, i + 1) for i, a in enumerate(A))[:6]
    
for _ in range(Q):
    K = int(input())
    to_remove_indices = list(map(int, input().split()))
    
    for value, index in smallest:
        if index not in to_remove_indices:
            print(value)
            break
