#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

vector<long long> inv;

long long pow(long long a, long long b)
{
    long long res = 1;
    if (b == 0)
    {
        return 1;
    }

    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % MOD;
            b -= 1;
        }

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

// compute c choose d
long long choose(long long c, long long d)
{
    // c ... (c - d + 1) / d!
    long long res = 1;
    for (long long i = c; i >= c - d + 1; i--)
    {
        res = res * (i % MOD) % MOD;
    }

    res = res * inv[d] % MOD;

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> in(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> p[i + 1];
        p[i + 1]--;
        in[p[i + 1]]++;
    }

    vector<long long> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    long long D = 0;
    vector<long long> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        D = max(D, d[i]);
    }

    // compute factorial inverses
    inv.resize(D + 1);
    long long df = 1;
    for (long long i = 1; i <= D; i++)
    {
        df = df * i % MOD;
    }
    inv[D] = pow(df, MOD - 2);
    for (long long i = D - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    // topological sort on the reversed graph
    vector<long long> r(n); // remaining candies in the subtree
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            q.push_back(i);
        }
    }

    long long res = 1;
    while (q.size())
    {
        int cur = q.front();
        q.pop_front();

        r[cur] += c[cur];
        if (r[cur] < d[cur])
        {
            cout << 0 << endl;
            return 0;
        }

        res = res * choose(r[cur], d[cur]) % MOD;
        r[p[cur]] += (r[cur] - d[cur]); // feed remaining to parents
        in[p[cur]]--;
        if (in[p[cur]] == 0)
        {
            q.push_back(p[cur]);
        }
    }

    cout << res << endl;
}