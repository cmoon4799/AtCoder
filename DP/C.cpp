#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll MOD = 998244353;

int main()
{
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    int as = a.size();
    int bs = b.size();
    int cs = c.size();

    vector<vector<vector<ll>>> dp(as, vector<vector<ll>>(bs, vector<ll>(cs)));
    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        vector<vector<vector<ll>>> ndp(as, vector<vector<ll>>(bs, vector<ll>(cs)));
        for (int ai = 0; ai < as; ai++)
        {
            for (int bi = 0; bi < bs; bi++)
            {
                for (int ci = 0; ci < cs; ci++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        char l = (char)('a' + j);
                        int x = ai + (a[ai] == l);
                        int y = bi + (b[bi] == l);
                        int z = ci + (c[ci] == l);

                        if (x == as || y == bs || z == cs)
                        {
                            continue;
                        }
                        ndp[x][y][z] = ndp[x][y][z] + dp[ai][bi][ci] % MOD;
                    }
                }
            }
        }
        swap(dp, ndp);
    }

    ll res = 0;
    for (int ai = 0; ai < as; ai++)
    {
        for (int bi = 0; bi < bs; bi++)
        {
            for (int ci = 0; ci < cs; ci++)
            {
                res = (res + dp[ai][bi][ci]) % MOD;
            }
        }
    }

    cout << res << endl;
}