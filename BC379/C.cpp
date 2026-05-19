#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// int: 32 bits -+ 2**9
// long: 32 or 64 bits depending on the platform
// long: long 64 bits -+ 9**18
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
    int n, m;

    cin >> n >> m;
    vector<ll> x(m);
    vector<ll> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
        x[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    vector<pair<ll, ll>> xa(m);
    for (int i = 0; i < m; i++)
    {
        xa[i] = pair<ll, ll>(x[i], a[i]);
    }
    sort(xa.begin(), xa.end());

    // consider the last two cells
    // (n - 2) (n - 1)
    // if x + y > 2 then we can break
    // x + y + z > 3 then we can break

    // why is every solution (spreading of stones)
    // optimal, or rather equivalent
    // consider an elevator starting on the first floor (cell)
    // at every cell, a fixed number of people must get off (if the cell is empty)
    // and get on (if the cell is not empty). in particular, the original floor a person is from does not matter! that is, it does not matter how long a person has travelled.

    ll c = 0;
    ll res = 0;
    for (int i = 0; i < m; i++)
    {
        if (c < xa[i].first)
        {
            cout << -1 << endl;
            return 0;
        }
        c += xa[i].second;
        res -= xa[i].first * xa[i].second;
    }
    if (c != n)
    {
        cout << -1 << endl;
        return 0;
    }
    res += n * (n - 1) / 2;

    cout << res << endl;
}
