#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int> w(N);
    vector<long long> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<long long>> dp(N, vector<long long>(W + 1));
    dp[0][w[0]] = v[0];
    for (int i = 1; i < N; i++)
    {
        for (int weight = 0; weight <= W; weight++)
        {
            if (w[i] > weight)
            {
                dp[i][weight] = dp[i - 1][weight];
            }
            else
            {
                dp[i][weight] = max(dp[i - 1][weight], v[i] + dp[i - 1][weight - w[i]]);
            }
        }
    }

    long long res = 0;
    for (int weight = 0; weight <= W; weight++)
    {
        res = max(res, dp[N - 1][weight]);
    }

    cout << res << endl;
}