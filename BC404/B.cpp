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

// rotate input vector a, i times
vector<string> rotate(vector<string> &a, int i)
{
    if (i == 0)
    {
        return a;
    }
    int n = a.size();
    vector<string> b(n, string(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[j][n - 1 - i] = a[i][j];
        }
    }

    return rotate(b, i - 1);
}

// spits out the number of differences between a, b
int differences(vector<string> &a, vector<string> &b)
{
    int c = 0;

    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[i][j])
            {
                c++;
            }
        }
    }
    return c;
}

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    vector<string> t(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    // rotate 0 <= i < 4 times
    // determine differences
    int res = n * n;
    for (int i = 0; i < 4; i++)
    {
        vector<string> r = rotate(s, i);
        res = min(res, differences(t, r) + i);
    }

    cout << res << endl;
    return 0;
}
