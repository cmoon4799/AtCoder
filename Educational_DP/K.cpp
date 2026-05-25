#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<bool> dp(k + 1);
    // dp[i]: can one win starting from i stones
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] <= i && !dp[i - a[j]])
            {
                dp[i] = true;
                break;
            }
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;
}