#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// int: 32 bits -+ 2**9
// long: 32 or 64 bits depending on the platform
// long long: 64 bits -+ 9**18
#define ll long long
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define endl "\n"

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;

// Utility functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// binary exponentiation
ll pow(ll x, ll y, ll MOD = 0)
{
    ll res = 1;
    while (y > 0)
    {
        if (y % 2)
        {
            res *= x;
            if (MOD != 0)
                res %= MOD;
            y -= 1;
        }
        else
        {
            x *= x;
            if (MOD != 0)
                x %= MOD;
            y /= 2;
        }
    }

    return res;
}

vector<vector<ll>> w;
int n, m;
ll res = pow(2, 60, 0) - 1;
// v: current
void dfs(int v, ll visited, ll cur)
{
    if (v == n - 1)
    {
        res = min(res, cur);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited & (1 << i) || w[v][i] == -1)
        {
            continue;
        }

        dfs(i, visited | (1 << i), cur ^ w[v][i]);
    }
}

int main()
{
    cin >> n >> m;

    w = vector<vector<ll>>(n, vector<ll>(n, -1));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll wt;
        cin >> x >> y >> wt;

        w[x - 1][y - 1] = wt;
        w[y - 1][x - 1] = wt;
    }

    dfs(0, 1, 0);
    cout << res << endl;
}
