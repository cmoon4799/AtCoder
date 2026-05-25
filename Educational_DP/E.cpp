#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    long long W;
    cin >> N >> W;

    vector<int> v(N), w(N);
    long long V = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
        V += v[i];
    }

    long long INF = 4e18;

    vector<long long> dp(V + 1, INF);
    dp[0] = 0;
    dp[v[0]] = w[0];
    for (int i = 1; i < N; i++)
    {
        for (long long value = V; value >= v[i]; value--)
        {
            dp[value] = min(dp[value], dp[value - v[i]] + w[i]);
        }
    }

    long long res = 0;
    for (long long value = V; value >= 0; value--)
    {
        if (dp[value] != INF && dp[value] <= W)
        {
            cout << value << endl;
            return 0;
        }
    }
}