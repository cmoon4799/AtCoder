#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

struct mint
{
    long long value;

    mint(long long value_ = 0)
    {
        value = value_ % MOD;
        if (value < 0)
        {
            value += MOD;
        }
    }

    mint &operator+=(const mint &other)
    {
        value = (value + other.value) % MOD;
        return *this;
    }

    mint &operator-=(const mint &other)
    {
        value = (value - other.value) % MOD;
        if (value < 0)
        {
            value += MOD;
        }
        return *this;
    }

    mint &operator*=(const mint &other)
    {
        value = (value * other.value) % MOD;
        return *this;
    }

    static mint modpow(mint base, long long exp)
    {
        mint res = 1;
        if (exp == 0)
        {
            return res;
        }

        while (exp > 0)
        {
            if (exp & 1)
            {
                res *= base;
                exp -= 1;
            }

            base *= base;
            exp >>= 1;
        }

        return res;
    }

    static mint inverse(mint a)
    {
        return modpow(a, MOD - 2);
    }

    mint &operator/=(const mint &other)
    {
        value = value * inverse(other).value % MOD;
        return *this;
    }

    friend mint operator+(mint a, mint const &b)
    {
        return a += b;
    }

    friend mint operator-(mint a, mint const &b)
    {
        return a -= b;
    }

    friend mint operator*(mint a, mint const &b)
    {
        return a *= b;
    }

    friend mint operator/(mint a, mint const &b)
    {
        return a /= b;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    // dp[bitmask]: number of ways to have assigned the women represented by the bitmask

    vector<vector<int>> bu(n + 1);
    for (int i = 0; i < (1 << n); i++)
    {
        bu[__builtin_popcount(i)].push_back(i);
    }

    vector<mint> dp(1 << n);
    dp[0] = 1;
    for (int pc = 0; pc < n; pc++)
    {
        for (auto mask : bu[pc])
        {
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i) || g[pc][i] == 0)
                {
                    continue;
                }
                dp[mask | (1 << i)] += dp[mask];
            }
        }
    }

    cout << dp[(1 << n) - 1].value << endl;
}