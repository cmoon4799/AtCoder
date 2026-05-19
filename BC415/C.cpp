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

// unchosen represents a

bool solver(int &n, string &s, int state, vector<bool> &visited)
{
    if (visited[state])
    {
        return false;
    }
    if (state == ((1 << n) - 1))
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        // choose state i if unchosen
        // cout << "new state: " << state + (1 << i) << endl;
        if (!(state & (1 << i)) && s[state + (1 << i) - 1] == '0')
        {
            // cout << "old state: " << state << endl;
            // cout << "chemical i: " << i << endl;
            visited[state] = true;
            if (solver(n, s, state + (1 << i), visited))
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    int state = 0;
    vector<bool> visited((1 << n) - 1, false);
    if (solver(n, s, state, visited))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
