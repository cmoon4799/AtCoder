#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<double> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    // dp[i][j]: probability of getting j heads among the first i coins
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][0] = dp[i][0] * (1 - p[i]);
        for (int j = 1; j <= n; j++)
        {
            dp[i + 1][j] = dp[i][j - 1] * p[i] + dp[i][j] * (1 - p[i]);
        }
    }
    double res = 0;
    for (int i = (n + 1) / 2; i <= n; i++)
    {
        res += dp[n][i];
    }

    cout << setprecision(15) << res << endl;
}