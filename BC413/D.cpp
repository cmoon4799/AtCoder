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

bool solver()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<ll, int> freq;
    for (ll v : a)
        freq[v]++;
    // smallest, second smallest -> find r
    ll x = 0;
    ll y = 1;
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i]) < abs(a[y]))
        {
            y = i;
        }
        if (abs(a[x]) > abs(a[y]))
        {
            swap(x, y);
        }
    }

    ll g = gcd(a[y], a[x]);
    ll c = a[x];
    y = a[y] / g;
    x = a[x] / g;

    auto it0 = freq.find(c);
    if (it0 == freq.end() || it0->second == 0)
        return false;
    it0->second--;

    for (int i = 0; i < n - 1; i++)
    {
        if (c % x != 0)
        {
            return false;
        }
        c /= x;
        c *= y;

        auto it = freq.find(c);
        if (it == freq.end() || it->second == 0)
            return false;
        it->second--;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        if (solver())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
