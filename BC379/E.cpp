#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// int: 32 bits -+ 2**9
// long: 32 or 64 bits depending on the platform
// long: long 64 bits -+ 9**18
#define int long long
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

template <typename T>
void print_vector(vector<T> &v)
{
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

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

vector<int> convert_to_vector(ll n)
{
    vector<int> res;
    do
    {
        int ones = n % 10;
        res.push_back(ones);

        n = (n - ones) / 10;
    } while (n);

    return res;
}

int32_t main()
{
    int n;
    cin >> n;
    string st;
    cin >> st;

    vector<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        s.push_back(st[i] - '0');
    }

    vector<int> ps(n);
    ps[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ps[i] = ps[i + 1] + s[i] * (n - i);
    }

    // print_vector(ps);
    vector<int> res(n + 10);
    for (int i = 0; i < n + 10; i++)
    {
        int t = res[i];
        if (i < n)
        {
            t += ps[i];
        }

        vector<int> psv = convert_to_vector(t);
        res[i] = psv[0];
        for (int j = 1; j < psv.size(); j++)
        {
            res[i + j] += psv[j];
        }
    }

    // print_vector(res);
    bool leading = false;
    for (int i = n + 9; i >= 0; i--)
    {
        if (res[i] != 0)
        {
            leading = true;
        }
        if (leading)
        {
            cout << res[i];
        }
    }
    cout << endl;
}
