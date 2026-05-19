#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// int: 32 bits -+ 2**9
// long: 32 or 64 bits depending on the platform
// long long: 64 bits -+ 9**18
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

vector<vector<pair<int, ll>>> e;
vector<bool> visited;
vector<ll> wt;
// reach out, if there's inconsistency then exit
vector<int> bfs(int start)
{

    vector<int> q = {start};
    visited[start] = true;
    vector<int> cc = {start};

    while (q.size())
    {
        int v = q.back();
        q.pop_back();
        for (int i = 0; i < e[v].size(); i++)
        {
            int w = e[v][i].first;
            ll z = e[v][i].second;

            if (visited[w])
            {
                if ((wt[v] ^ z) != wt[w])
                {
                    cout << -1 << endl;
                    exit(0);
                }
            }
            else if (!visited[w])
            {
                visited[w] = true;
                cc.push_back(w);
                q.push_back(w);
                wt[w] = wt[v] ^ z;
            }
        }
    }

    return cc;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    // a_2 ^ a_3 = z_k, (2, k)
    e = vector<vector<pair<int, ll>>>(n);
    visited = vector<bool>(n);
    wt = vector<ll>(n, 0);
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        e[x - 1].push_back(pair<int, ll>(y - 1, z));
        e[y - 1].push_back(pair<int, ll>(x - 1, z));
    }

    vector<ll> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        vector<int> cc = bfs(i);
        // go through weights of each vertex in the component
        // determine minimum sum
        // for each bit position determine the minimum bit for the sum
        for (int bp = 0; bp <= 30; bp++)
        {
            int cnt = 0;
            for (int j = 0; j < cc.size(); j++)
            {
                if (wt[cc[j]] & (1 << bp))
                {
                    cnt += 1;
                }
                ans[cc[j]] |= (wt[cc[j]] & (ll)(1 << bp));
            }

            if (cc.size() - cnt < cnt)
            {
                for (int j = 0; j < cc.size(); j++)
                {
                    ans[cc[j]] ^= (ll)(1 << bp);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
