import sys
input = sys.stdin.readline

MOD = 998244353

n = int(input())
d = list(map(int, input().split()))

dp = {
    n - 1: 1,
    n - 2: 1,
}

coef = 1

# Optional: precompute inverses of 1..n in O(n)
inv = [0] * (n + 1)
inv[1] = 1
for x in range(2, n + 1):
    inv[x] = MOD - (MOD // x) * inv[MOD % x] % MOD

for i in range(n - 3, -1, -1):
    j = i + d[i]
    v = dp.get(j, 0)

    if d[i] == d[i + 1]:
        c = n - i - 2
        coef = coef * c % MOD

        add = v * inv[c] % MOD

        dp[j] = (dp.get(j, 0) + add) % MOD
        dp[i] = (dp.get(i, 0) + add) % MOD

    else:
        dp.clear()
        dp[j] = v
        dp[i] = (dp.get(i, 0) + v) % MOD

ans = sum(dp.values()) % MOD
print(ans * coef % MOD)
