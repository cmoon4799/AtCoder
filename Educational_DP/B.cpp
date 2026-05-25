#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < min(n, i + k + 1); j++)
        {
            if (dp[i] == -1)
            {
                dp[i] = abs(h[i] - h[j]) + dp[j];
            }
            else
            {
                dp[i] = min(dp[i], abs(h[i] - h[j]) + dp[j]);
            }
        }
    }

    cout << dp[0] << endl;
}