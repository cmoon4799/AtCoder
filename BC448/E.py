import math


def phi(n):
    result = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1
    if n > 1:
        result -= result // n
    return result

def order(a, M):
    if math.gcd(a, M) != 1:
        return None
    
    p = 2
    d = phi(M) # from which we remove divisors
    k = d # candidate order
    
    while p * p <= d:
        if d % p == 0:
            while k % p == 0 and pow(a, k // p, M) == 1:
                k //= p
            while d % p == 0:
                d //= p
        p += 1
    
    if d > 1:
        while k % d == 0 and pow(a, k // d, M) == 1:
            k //= d
    
    return k

K, M = map(int, input().split())
MOD = 10007

C, L = [], []
for _ in range(K):
    c, l = map(int, input().split())
    C.append(c)
    L.append(l)

T = 10
if M % 2 == 0:
    M //= 2
    T //= 2
if M % 5 == 0:
    M //= 5
    T //= 5

Q = 0
R = 0
k = 0
o = order(T, M)

if T == 1:
    pass

for i in range(K - 1, -1, -1):
    c, l = C[i], L[i]
    
    l %= o
    r = (T**(o + 1) - 1)//(T - 1)
    r *= 10**(k % o)
    r *= c
    r %= M
    
    
    
    k += l
    
    
    