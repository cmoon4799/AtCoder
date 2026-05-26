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

void dfs(int c, vector<int> &p, vector<bool> &s, vector<vector<int>> &e)
{
    s[c] = true;
    for (auto v : e[c])
    {
        if (!s[v])
        {
            p[v] = c;
            dfs(v, p, s, e);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    // root the tree
    // topological sort on the reverse rooted tree
    // handle dp based on subtrees
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> p(n);
    vector<bool> s(n);
    dfs(0, p, s, e);

    vector<int> in(n);
    for (int i = 1; i < n; i++)
    {
        in[p[i]]++;
    }

    deque<int> q;
    vector<vector<mint>> dp(n, vector<mint>(2)); // 0 - white, 1 - black
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            q.push_back(i);
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
    }

    while (q.size())
    {
        int c = q.front();
        q.pop_front();

        mint white = 1;
        mint black = 1;
        for (auto v : e[c])
        {
            if (v == p[c])
            {
                continue;
            }

            white *= (dp[v][0] + dp[v][1]);
            black *= dp[v][0];
        }

        dp[c][0] = white;
        dp[c][1] = black;

        in[p[c]]--;
        if (in[p[c]] == 0)
        {
            q.push_back(p[c]);
        }
    }

    cout << (dp[0][0] + dp[0][1]).value << endl;
}