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

// return size of the connected component
int dfs(int v, vector<bool> &seen, vector<vector<int>> &edges)
{
    seen[v] = true;

    int ccs = 0;
    for (auto u : edges[v])
    {
        if (!seen[u])
        {
            ccs += dfs(u, seen, edges);
        }
    }

    return 1 + ccs;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    if (m != n)
    {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (e[i].size() != 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    // need the fact that it's connected
    // do dfs
    vector<bool> seen(n, false);
    if (dfs(0, seen, e) != n)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}
