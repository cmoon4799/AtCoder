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
    int n, m;
    cin >> n >> m;

    vector<ll> b(n);
    vector<ll> w(m);

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> w[i];
    }

    // choose all positive numbers from b
    sort(b.begin(), b.end());
    sort(w.begin(), w.end());

    ll total = 0;
    int k = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (b[i] > 0)
        {
            total += b[i];
            k += 1;
        }
        else
        {
            break;
        }
    }

    for (int i = m - 1; i >= max(m - k, 0); i--)
    {
        if (w[i] > 0)
        {
            total += w[i];
        }
        else
        {
            break;
        }
    }

    int i = n - 1 - k;
    int j = m - 1 - k;
    // cout << total << " " << i << " " << j << endl;
    while (i >= 0 && j >= 0 && b[i] + w[j] > 0)
    {
        total += b[i] + w[j];
        i -= 1;
        j -= 1;
    }

    cout << total << endl;
}
