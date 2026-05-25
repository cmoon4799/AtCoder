#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long MAX = 4e16;

    vector<vector<long long>> dp(n, vector<long long>(n, MAX));
    // prefix sums
    vector<long long> ps(n + 1);
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
        ps[i + 1] = a[i] + ps[i];
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i < n - length + 1; i++)
        {
            // i .. j
            for (int j = i; j < i + length - 1; j++)
            {
                long long cost = dp[i][j] + dp[j + 1][i + length - 1];
                cost += (ps[j + 1] - ps[i]);
                cost += (ps[i + length] - ps[j + 1]);
                dp[i][i + length - 1] = min(dp[i][i + length - 1], cost);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}