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

    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = a[i];
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i < n - length + 1; i++)
        {
            dp[i][i + length - 1] =
                max(a[i] - dp[i + 1][i + length - 1], a[i + length - 1] - dp[i][i + length - 2]);
        }
    }

    cout << dp[0][n - 1] << endl;
}