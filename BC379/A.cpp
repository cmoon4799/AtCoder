#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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

void solve()
{
    // Write solution logic here
}

// suppose you have an arbitrarily long number and you want to convert it into a vector<int>
// representing each digit
// e.g. 123 -> <1, 2, 3>

// binary exponentiation
ll pow(ll x, ll y, ll MOD = 0) { 
    ll res = 1;
    while (y > 0)
    {
        if (y % 2)
        {
            res *= x; if (MOD != 0)
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

vector<int> convert(int n)
{
    vector<int> v;

    int place = 1;
    while (n > 0)
    {
        int ones_digit = n % 10;
        v.push_back(ones_digit);
        n -= ones_digit;
        n /= 10;
    }

    reverse(v.begin(), v.end());
    return v;
}

int main()
{

    int N;
    cin >> N;

    vector<int> v = convert(N);
    int x = v[0], y = v[1], z = v[2];

    cout << y << z << x << " " << z << x << y << endl;
}
