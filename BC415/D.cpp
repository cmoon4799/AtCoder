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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int m;
    cin >> n >> m;

    vector<pair<long long, long long>> p;
    for (int i = 0; i < m; i++)
    {
        long long x;
        long long y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }

    sort(p.begin(), p.end(), [](auto &x, auto &y)
         { return (x.first - x.second) < (y.first - y.second); });

    // while we have colas, choose the first in the list such that p.first <= n
    long long res = 0;
    while (true)
    {
        bool found = false;
        for (int i = 0; i < m; i++)
        {
            if (p[i].first <= n)
            {
                ll k = (n - p[i].first) / (p[i].first - p[i].second) + 1;
                n -= k * (p[i].first - p[i].second);
                res += k;
                found = true;
                break; // restart from i = 0
            }
        }
        if (!found)
            break;
    }

    cout << res << endl;
    return 0;
}
